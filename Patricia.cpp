#include <iostream>
#include "Patricia.hpp"
using namespace std;

bool Patricia::insere(string prefixo){
    if (getRaiz() == nullptr) {
        cout << "raiz == nullprt" << endl;
        setRaiz(new Node());
        raiz->setPrefixo(prefixo);
        return true;
    } else {
        return insereRec(prefixo, getRaiz());
    }
    return false;  
}

bool Patricia::insereRec(string prefixo, NodeApd node){
    int divergencia = AchaNivel(prefixo, node->getPrefixo());
    if (node->isFolha()) {
        if (node->getPrefixo() == prefixo){
            cout << "prefixo == node->prefixo" << endl;
            return false;
        } else {
            cout << "prefixo != node->prefixo" << endl;
            // define o pai do no a direita
            Node* direita = new Node(node);

            // define o prefixo do nó a esquerda
            direita->setPrefixo(string(prefixo, divergencia));

            // pai deixa de ser folha
            node->setFolha(false);

            // pai recebe o filho a esquerda
            node->setFilhoDireita(direita);

            node->setLetra(node->getPrefixo().c_str()[divergencia]);
            // define o possivel prefixo do pai (node)
            string node_prefixTemp = (string(node->getPrefixo(), 0, divergencia));
            if (divergencia < node->getPrefixo().length()) {
                // define o pai do no a esquerda
                Node* esquerda = new Node(node);
                esquerda->setPrefixo(string(node->getPrefixo(), divergencia));
                node->setFilhoEsquerda(esquerda);
            }

            // verifica se o node->prefixo mudou
            if (node_prefixTemp != node->getPrefixo()){
                // se mudou, deixou de ser terminal
                node->setTerminal(false);
                node->setPrefixo(node_prefixTemp);
            }
            return true;
        } 
    } else {
        /* busca no para inserir prefixo */
        if (divergencia == 0 && getContador()){
            Node* nova_raiz = new Node();
            Node* direita = new Node(nova_raiz); // define uma nova folha
            direita->setPrefixo(prefixo); // atribui o prefixo a folha
            nova_raiz->setLetra(getRaiz()->getPrefixo().c_str()[0]); // adiciona a letra divegente
            nova_raiz->setDivergencia(1); // adiciona o indice divergente
            nova_raiz->setFilhoEsquerda(getRaiz()); // a antiga raiz vira filho a esquerda da nova raiz
            nova_raiz->setFilhoDireita(direita); // define o filho da nova raiz a direita
            nova_raiz->setFolha(false);
            nova_raiz->setTerminal(false);
            setContador(false); // não deixa adicionar um novo no como raiz
            getRaiz()->setPai(nova_raiz); // adiciona um pai a raiz atual
            setRaiz(nova_raiz); // define a nova raiz como raiz
            return true;
        } else if (!getContador() && divergencia == 0) {
            cout << "Error: insert" << endl;
            return false;
        } else if (prefixo.c_str()[divergencia] == node->getLetra()) {
            /* vai pra esquerda se node->prefix = bcd e novo prefix = abc*/
            return insereRec(string(prefixo, divergencia, -1), node->getFilhoEsquerda());
        } else {
            /* vai pra direita */
            /* vai pra direita se node->prefix = bcd e novo prefix = cbc*/
            return insereRec(string(prefixo, divergencia, -1), node->getFilhoDireita());
        }
    }
}

// calcula o indice de divergencia
unsigned int Patricia::AchaNivel (const std::string& k1, const std::string& k2) {
    const char *p0 = k1.c_str();
    const char *p1 = k1.c_str();
    const char *p2 = k2.c_str();
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
        p1++; p2++;
    }
    unsigned int nivel = p1-p0;
    std::cout << " AchaNivel: k1=" << k1 << " k2=" << k2 << " nivel=" << nivel << std::endl;
    return (nivel);
}

// verifica se s1 tem pre como prefixo
bool Patricia::ComecaCom (const std::string& s1, const std::string& pre) {
    const char *p1 = s1.c_str(), *p2 = pre.c_str();
    while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
        p1++; p2++;
    }
    if (*p2 == '\0' && *p1 != '\0') {
        return true;
        
    } else {
        return false;
    }
}

int main(int argc, char const *argv[]) {
    Patricia pat;
    string palavra = "cascolho";
    string palavra1 = "cascalho";
    string palavra2 = "cascalhe";
    string palavra3 = "bascalhe";
    string palavra4 = "vascalhe";
    pat.insere(palavra);
    pat.insere(palavra1);
    pat.insere(palavra2);
    pat.insere(palavra3);
    cout << pat.getContador() << endl;
    pat.insere(palavra4);
    cout << pat.getRaiz()->getPrefixo() << pat.getRaiz()->getLetra() << endl;
    cout << pat.getRaiz()->getFilhoEsquerda()->getPrefixo() << endl;
    cout << pat.getRaiz()->getFilhoEsquerda()->getFilhoEsquerda()->getPrefixo() << endl;
    cout << pat.getRaiz()->getFilhoEsquerda()->getFilhoDireita()->getPrefixo() << endl;
    cout << pat.getRaiz()->getFilhoEsquerda()->getFilhoDireita()->getFilhoEsquerda()->getPrefixo() << endl;
    cout << pat.getRaiz()->getFilhoEsquerda()->getFilhoDireita()->getFilhoDireita()->getPrefixo() << endl;
    cout << pat.getRaiz()->getFilhoDireita()->getPrefixo() << endl;
    /*
    pat.insere("bbcdef");
    cout << pat.getRaiz()->getFilhoDireita()->getPrefixo() << endl;
    int divergencia = pat.AchaNivel(palavra1, palavra);
    cout << pat.getRaiz()->getPrefixo() << endl;
    cout << divergencia << endl;
    cout << palavra.c_str()[divergencia] << endl;
    cout << ('\0' < 'a') << endl;
    cout << pat.AchaNivel("abc", "abcd") << endl; 
    cout << pat.ComecaCom("abcd", "abc") << endl; 
    */

    return 0;
}