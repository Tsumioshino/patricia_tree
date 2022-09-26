package arvore.patricia;
// Java Program to implement Patricia trie

import javax.swing.JOptionPane;

/**
 * App
 */
public class App {

    public static void main(String[] args) {
		PatriciaTest pt = new PatriciaTest();

        Opcoes resposta;
		do {
            
            try {
                resposta = (Opcoes) JOptionPane.showInputDialog(null, "Escolha uma opção", "Opções", JOptionPane.QUESTION_MESSAGE, null, Opcoes.values(), Opcoes.INSERIR);

                switch (resposta) {
                    case INSERIR -> {
                        pt.insert(Integer.parseInt(JOptionPane.showInputDialog(null, "Digite o valor a ser buscado")));
                        
                    }
                    case BUSCAR -> {    
                        boolean r = pt.search(Integer.parseInt(JOptionPane.showInputDialog(null, "Digite um valor")));
                        if (r) {
                            JOptionPane.showMessageDialog(null, "Valor encontrado");
                        } else {
                            JOptionPane.showMessageDialog(null, "Valor não encontrado");
                        }
                    }
                    case ESVAZIAR ->{
                        int confirm = JOptionPane.showConfirmDialog(null, "Você tem certeza?");
                        if (confirm == 0){
                            pt.makeEmpty();
                        }
                        JOptionPane.showMessageDialog(null, "Patricia esvaziada");
                    }
                    case ESTAVAZIO -> {
                        boolean r = pt.isEmpty();
                        if (r) {
                            JOptionPane.showInputDialog(null, "A Patricia está vazia");
                        } else {
                            JOptionPane.showInputDialog(null, "A Patricia não está vazia");
                        }
                        
                    }
                    case SAIR -> {JOptionPane.showMessageDialog(null, "Até mais");}
                }
            } catch (Exception e) {
                resposta = Opcoes.SAIR;
            } 
        } while (resposta != Opcoes.SAIR);
	}
}

