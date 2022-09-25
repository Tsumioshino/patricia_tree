#ifndef PATRICIA_H
#include <iostream>
#include <string>

typedef struct Patricia *PatriciaApd;
typedef struct Node *NodeApd;

class Patricia {
    private:
        void Lista_aux(NodeApd, std::string);
        NodeApd busca_aux(std::string, NodeApd);
        void GeraDotAux(NodeApd, std::stringstream&);
    protected:
        NodeApd raiz = nullptr;
        bool contador = true;
    public:
        bool insere(std::string);
        bool insereRec(std::string, NodeApd);
        unsigned int AchaNivel (const std::string&, const std::string&);
        bool ComecaCom (const std::string&, const std::string&);
        NodeApd getRaiz(){return raiz;};
        void setRaiz(NodeApd node) {raiz = node;}
        void setContador(bool resp) {contador = resp;};
        bool getContador(){return contador;};
        void Lista();
        NodeApd busca(std::string);
        void GeraDot();
};

class Node {
    protected:
        NodeApd esquerda = nullptr;
        NodeApd direita = nullptr;
        NodeApd pai = nullptr;
        std::string prefixo;
        char letra_divergida;
        int divergencia;
        int id;
        bool folha = true;
        bool terminal = true;
        int nivel;
    public:
        Node() {folha = true; terminal = true;};
        Node(NodeApd node) {folha = true; terminal = true; pai = node;};
        // Define um nó como folha (true/false)
        void setFolha(bool resposta) {folha = resposta;};
        // Pergunta se um nó é folha
        bool isFolha() { return folha; };
        // Define um nó como terminal (true/false)
        void setTerminal(bool resposta) {terminal = resposta;};
        // Pergunta se um nó é terminal
        bool isTerminal() { return terminal; };
        // Define um prefixo para o no
        void setPrefixo(std::string pref) {prefixo = pref;};
        // Recupera o prefixo do nó
        std::string getPrefixo() {return prefixo;};
        // Define o filho a esquerda
        void setFilhoEsquerda(NodeApd node){esquerda = node;};
        NodeApd getFilhoEsquerda() {return esquerda;};
        // Define o filho a direita
        void setFilhoDireita(NodeApd node){direita = node;};
        NodeApd getFilhoDireita() {return direita;};
        // Define o pai do no
        void setPai(NodeApd node) {pai = node;};
        NodeApd getPai() {return pai;};
        // Define a divergencia entre duas strings
        void setDivergencia(int divergencia){divergencia = divergencia;};
        int getDivergencia() {return divergencia;};
        void setLetra(char letra){letra_divergida = letra;};
        char getLetra() {return letra_divergida;};
        void setId(int i){id = i;};
        int getId() {return id;};
        void setNivel(int i){nivel = i;};
        int getNivel() {return nivel;};
        std::string to_string(){ 
            if (pai != nullptr){
                return (pai->to_string() + ("{" + prefixo + "}"));
            } else {
                return (prefixo);
            }
        };
};

#endif