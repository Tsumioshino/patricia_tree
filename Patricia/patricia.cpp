#include "patricia.h"
#include <iostream>
#include <sstream>
#include <memory>
#include <cstring>

using namespace std;

/* Construtor do Nó básico
 * Incremente o contador da árvore Patricia e usa dele como o ID do nó */
Node::Node(uint8_t t, const string &c) : tipo(t), chave(c) {
    this->id = ++Patricia::contador;
}

Node::~Node() {};

Folha::~Folha() {};

Interno::~Interno() {
    /* Deleta os nos presentes no array */
    for (int i=0; i<NUMARY; i++) {
        Patricia::Delete(&ponteiros[i]);
    }
}

/* Calcula a altura de um nó interno */
int Interno::Altura() {
    /* A altura começa com 0 */
    int altura=0;

    /* Pecorre os filhos do no */
    for (int i=0; i<NUMARY; i++) {
        if (ponteiros[i]) {
            int tmp=0;
            NodeApd const ptr = ponteiros[i];

            /* Recupe a altura do no */
            if (ptr->isFolha()) {
                tmp = ((Folha*) (ptr))->Altura();
            } else if (ptr->isInterno()) {
                tmp = ((Interno*) (ptr))->Altura();
            }
            altura = max(altura, tmp);
        }
    }

    /* Incremente a altura do maior filho e retorne */
    return ++altura;
}

/* Define um contador para recuperar no dot */
unsigned int Patricia::contador = 0;

void Patricia::Insere(const string &chave, const string &conteudo) {
    return Patricia::Insere(chave, PayLoad(conteudo));
}

/* Recupera a posição do caracter diferente */
char Patricia::AchaChar(const string &in, unsigned int nivel) {
    return in.c_str()[nivel];
}


/* Insere o PayLoad na árvore */
void Patricia::Insere(const string& chave, const PayLoad &pay) {

    /* Se a raiz é nula podemos inserir uma folha nela e terminar */
    if (raiz == nullptr) {
        auto node_novo = new Folha(chave, pay);
        raiz = node_novo;
        return;
    } else if (raiz->isFolha()) { /* Se a raiz é uma simples folha, divide o prefixo de na letra diferente para inserir em outro no o restante */
        if (raiz->Chave() == chave) { // Verifica se o elemento já foi inserido
            return;
        }
        /* Cria um nó novo contendo o payload */
        auto node_novo = new Folha(chave, pay);
        InsereAux(&raiz, raiz, node_novo);
        return;
    } else if (raiz->isInterno() && !IniciaCom(chave, raiz->Chave())) {
        /* Se não tiver o prefixo da chave, criamos um nó novo contendo o payload */
        auto node_novo = new Folha(chave, pay);
        /* E inserimos um nó interno entre a raiz, o nó original que ela apontava e este novo */
        InsereAux(&raiz, raiz, node_novo);
        return;
    }

    /* Procura pela chave na árvore */
    auto aux = Busca(chave, false);

    /* Se achou termina */
    if (aux.achou) { 
        return;
    } else if ((aux.q != nullptr) && (*(aux.q) == nullptr)) { // obriga a arvore a ser binaria
        return;
    } else {
        /* Se não, prossiga criando um nó interno e inserindo a chave neste nó */
        auto node_novo = new Folha(chave, pay);
        InsereAux(aux.q, *(aux.q), node_novo);
        return;
    }

}

void Patricia::InsereAux(NodeApd *node_superior, NodeApd node_inferior, NodeApd node_novo) {

    /* Salva as chaves */
    const string& chave_novo = node_novo->chave;
    const string& chave_inferior = node_inferior->chave;

    /* Acha o nivel que as strings divergem e o caractere de cada uma */
    const  unsigned int nivel = AchaNivel(chave_inferior, chave_novo);
    const char p_novo = AchaChar(chave_novo, nivel);
    const char p_inferior = AchaChar(chave_inferior, nivel);

    /* Realiza o particionamento transformando ex: abcd | abed -> ed */
    auto node_interno = new Interno(string(chave_novo, 0, nivel), nivel);

    /* Preparamos o no interno, com o nivel e as duas folhas */
    node_interno->ponteiros[ Traducao::Direta[(uint) p_novo] ] = node_novo;
    node_interno->ponteiros[ Traducao::Direta[(uint) p_inferior] ] = node_inferior;

    /* Apontamos o nó superior para o novo nó interno */
    (*node_superior) = node_interno;
    return;
}

/* Remove a chave da árvore */
bool Patricia::Remove (const string& chave) {
    /* Realiza a busca */
    auto r = Busca(chave, false);

    /* Se não achou a chave termina */
    if (!r.achou) {
        return false;
    }

    /* Remove o nó contendo a chave */
    Patricia::Delete(r.q);

    /* Se existir um nó superior, vamos verificar se ele contem somente um filho
     * Se isso for verdade, podemos remover este nó e ligar direto o nó acima dele com o filho dele,
     * eliminando o nó superior ao removido inicialmente */

    /* O nó P existe e é válido? */
    if (r.p && (*r.p)) {
        /* Transforma o ponteiro em Nó Interno */
        auto tmp = (Interno*) (*r.p);
        int nfilhos = 0;
        NodeApd* nodeptr = nullptr;

        /* Checa o número de filhos e salva o ponteiro para o filho encontrado */
        for (int i=0; i<NUMARY && nfilhos < 2;i++) {
            if (tmp->ponteiros[i]) {
                nfilhos++;
                nodeptr = &tmp->ponteiros[i];
            }
        }

        /* Se encontrar o filho, substitua o link do nó pelo filho, eliminando o nó interno */
        if (nfilhos == 1 && nodeptr && (*nodeptr) != nullptr) {
            /* Salvamos em tmp o nó filho */
            NodeApd tmp = (*nodeptr);

            /* Marcamos ele como nulo para não ser apagado junto do nó P */
            (*nodeptr) = nullptr;

            /* Apagamos para onde P aponta */
            Patricia::Delete(r.p);

            /* Ligamos o nó P ao filho salvo */
            *(r.p) = tmp;
        }
    }
    return true;
}

/* Faz a busca por uma chave na árvore */
RetornoBusca Patricia::Busca(const string& chave, bool simples) const {
    /* Cria o objeto de retorno da busca */
    RetornoBusca r;
    /* Se não existir uma raiz, a busca é falsa */
    if (!raiz) {
        return r;
    } else if (simples) { /* Faz a busca recursiva a partir da raiz */
        BuscaAuxiliarSimples(chave, &raiz, &r);
    } else {
        BuscaAuxiliar(chave, &raiz, &r);
    }
    return r;
}

/* Função recursiva para a Busca */
void Patricia::BuscaAuxiliar(const string& chave, const NodeApd* no, RetornoBusca* r) {
    /* Move os ponteiros p e q */
    r->p = r->q;
    r->q = const_cast<NodeApd*>(no);

    if (no == nullptr || *no == nullptr) {
        return;
    } else if ((*no)->isInterno()) { /* Se o nó for interno */
        auto tmp = (Interno*) *no;

        /* Se o prefixo do nó for diferente da chave podemos retornar */
        if (!IniciaCom(chave, tmp->chave)) {
            return;
        }

        /* Caso contrário vamos procurar o ramo a seguir */
        char letra = AchaChar(chave, tmp->nivel);
        NodeApd* no2 = &tmp->ponteiros[Traducao::Direta[(uint) letra]];

        /* E chamar a busca recursiva a partir deste ramo */
        BuscaAuxiliar(chave, no2, r);
        return;
    }

    /* Se o nó for folha */
    if ((*no)->isFolha()) {
        auto tmp = (Folha*) *no;

        /* Se a chave do nó for a procurada */
        if (tmp->chave == chave) {
            /* colocamos o conteudo no objeto de retorno e marcamos a busca verdadeira */
            r->payload = tmp->payload();
            r->achou = true;
            return;
        }
        /* Podemos retornar pois chegamos a uma folha */
        return;
    }
    return;
}

/* Função recursiva para a Busca */
void Patricia::BuscaAuxiliarSimples(const string& chave, const NodeApd* no, RetornoBusca* r) const {
    if (no == nullptr || *no == nullptr) return;

    /* Se o nó for interno */
    if ((*no)->isInterno()) {
        auto tmp = (Interno*) *no;
        /* Vamos procurar o ramo a seguir */
        char letra = AchaChar(chave, tmp->nivel);
        NodeApd* no2 = &tmp->ponteiros[Traducao::Direta[(uint) letra]];

        /* E chamar a busca recursiva a partir deste ramo */
        BuscaAuxiliarSimples(chave, no2, r);
        return;
    }

    /* Se o nó for folha */
    if ((*no)->isFolha()) {
        auto tmp = (Folha*) *no;

        /* Se a chave do nó for a procurada */
        if (tmp->chave == chave) {
            /* colocamos o conteudo no objeto de retorno e marcamos a busca verdadeira */
            r->payload = tmp->payload();
            r->achou = true;
            return;
        }
        /* Podemos retornar pois chegamos a uma folha */
        return;
    }
    return;
}

/* Encontra o nível em que as duas strings ficam diferentes */
unsigned int Patricia::AchaNivel (const string& k1, const string& k2) {
    const char *p0, *p1, *p2;
    p0 = k1.c_str();
    p1 = k1.c_str();
    p2 = k2.c_str();
    /* Enquanto p1 e p2 não chegam ao fim das strings e são iguais incremente */
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
        p1++; p2++;
    }
    /* O nível é a diferença entre o começo da string k1 (p0) e o nível em que divergiram (p1) */
    unsigned int nivel = p1-p0;
    return (nivel);
}

/* verifica se pre é prefixo de s1 */
bool Patricia::IniciaCom (const string& s1, const string& pre) {
    const char *p1 = s1.c_str(), *p2 = pre.c_str();
    return (memcmp(p1, p2, pre.size())==0);
}



/* Calcula o número de filhos de um nó interno ao contar a quantidade de elementos no apontador */
unsigned int Interno::QtdFilhos(void) const {
    unsigned int r = 0;
    for (int i=0; i<NUMARY; i++) {
        if (ponteiros[i]) r++;
    }
    return r;
}



/* Faz arvore vazia */
void Patricia::Limpa(void) {
    /* Como o destruidor do nó Interno é recursivo podemos apagar a raiz simplesmente */
    Patricia::Delete(&raiz);
    raiz=nullptr;
}


/* Calcula a altura da árvore patricia */
int Patricia::Altura() {
    if (raiz==nullptr) {
        return 0;
    } else if (raiz->isFolha()) {
        return ((Folha*) (raiz))->Altura();
    } else if (raiz->isInterno()) {
        return ((Interno*) (raiz))->Altura();
    } else {
        return 0;
    }
}

/* Deleta um no da memória */
void Patricia::Delete(NodeApd *no) {
    if (no==nullptr || *no==nullptr) {
        return;
    } else if ((*no)->isInterno()) {
        delete (Interno*) *no;
    } else if ((*no)->isFolha()) {
        delete (Folha*) *no;
    } else {
        delete *no;
    }
    *no = nullptr;
    return;
}


/* Gera um arquivo DOT para a árvore */
string Patricia::GeraDot(void) const {
    /* definicoes contem a parte de definicoes de nodes do DOT
     * ligacoes contem a parte das ligacoes entre os nodes do DOT */
    stringstream definicoes, ligacoes;

    /* Gera todas as definicoes e ligacoes recursivamente a partir da raiz */
    GeraDotAux(definicoes, ligacoes, raiz);

    /* Vamos montar o arquivo DOT em tmp */
    stringstream tmp;

    /* Inicia o digraph com o tipo de nó padrão como "record" */
    tmp << "digraph Teste {" << endl << " node [shape=record];" << endl;

    /* Cria uma raiz com um circulo duplo */
    tmp << "raiz [shape=doublecircle,label=\"RAIZ\"];" << endl;

    /* Insere as definicoes */
    tmp << definicoes.str();

    /* Gera a ligação da raiz para o primeiro nó */
    if (raiz) tmp << "raiz->no" << raiz->id << ";" << endl;

    /* Insere as ligacoes */
    tmp << ligacoes.str();

    /* Termina o DOT */
    tmp << "}" << endl;

    return tmp.str();
}

/* Funcao recursiva para gerar o DOT */
void Patricia::GeraDotAux(stringstream& definicoes, stringstream& ligacoes, NodeApd no) const {
    /* Se o nó é nulo não precisa fazer nada */
    if (no == nullptr) {
        return;
    } else if (no->isFolha()) { /* Se o nó é folha, insira a definicao dele apenas */
        Folha* tmp = (Folha*) no;
        definicoes << "no" << tmp->id << " [shape=ellipse, label=\"" << tmp->chave << "\"];" << endl;
        return;
    } else if (no->isInterno()) { /* Se o nó é interno é preciso também inserir as ligacoes */
        Interno* tmp = (Interno*) no;
        /* Definicao do nó */
        definicoes << "no" << tmp->id << " [label=\"{<f0> " << tmp->nivel << "| <f1> " << tmp->chave <<  "| {";

        /* Para cada filho do nó interno vamos inserir o quadrado dele na definicao e sua ligacao */
        bool virgula = false;
        for (int i=0; i < NUMARY; i++) {
            /* Se o filho existe */
            if (tmp->ponteiros[i]) {
                /* Precisamos inserir uma | somente apos o primeiro item */
                if (virgula) definicoes << " | ";
                else virgula = true;

                /* Definicoes no nó interno e ligacoes do nó interno com o filho */
                definicoes << "<f" << Traducao::Reversa2[i] << "> " << Traducao::Reversa[i];
                ligacoes << "no" << tmp->id << ":f" << Traducao::Reversa2[i] << " -> no" << tmp->ponteiros[i]->id << (tmp->ponteiros[i]->isFolha() ? "" : ":f0") << ";" << endl;
            }
        }

        /* Terminamos a definicao do nó interno */
        definicoes << "}}\"];" << endl;

        /* E vamos chamar a função recursiva para cada filho válido */
        for (int i=0; i < NUMARY; i++) {
            if (tmp->ponteiros[i])
                GeraDotAux(definicoes, ligacoes, tmp->ponteiros[i]);
        }
        return;
    }
}