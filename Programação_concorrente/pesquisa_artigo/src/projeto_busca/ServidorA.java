package projeto_busca;

import org.json.JSONArray;
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class ServidorA {
    private static final int PORTA_CLIENTE = 12345;
    private static final String HOST_B = "localhost";
    private static final int PORTA_B = 12346;
    private static final String HOST_C = "localhost";
    private static final int PORTA_C = 12347;

    public static void main(String[] args) throws IOException {
        System.out.println("Servidor A pronto! Na porta " + PORTA_CLIENTE);

        try (ServerSocket socketServidor = new ServerSocket(PORTA_CLIENTE)) {
            while (true) {
                //Aguarda a conexão do Cliente
                try (Socket socketCliente = socketServidor.accept()) {
                    System.out.println(" Cliente conectado: " + socketCliente.getInetAddress().getHostAddress());
                    
                    BufferedReader leitorCliente = new BufferedReader(new InputStreamReader(socketCliente.getInputStream()));
                    PrintWriter escritorCliente = new PrintWriter(socketCliente.getOutputStream(), true);

                    //Lê a requisição do Cliente
                    String requisicaoJson = leitorCliente.readLine();
                    System.out.println("Servidor A recebeu do cliente: " + requisicaoJson);

                    //Consulta o Servidor B (de forma sequencial)
                    System.out.println("Consultando Servidor B...");
                    JSONArray resultadosB = consultarServidor(HOST_B, PORTA_B, requisicaoJson);
                    System.out.println("⬅️  Recebeu " + resultadosB.length() + " itens do Servidor B.");

                    //consulta o Servidor C (de forma sequencial)
                    System.out.println("➡️  Consultando Servidor C...");
                    JSONArray resultadosC = consultarServidor(HOST_C, PORTA_C, requisicaoJson);
                    System.out.println("⬅️  Recebeu " + resultadosC.length() + " itens do Servidor C.");
                    
                    //Junta os resultados
                    JSONArray resultadoFinal = new JSONArray();
                    resultadosB.forEach(resultadoFinal::put);
                    resultadosC.forEach(resultadoFinal::put);

                    // Envia o resultado final para o cliente
                    escritorCliente.println(resultadoFinal.toString());
                    System.out.println("📦 Resultado final com " + resultadoFinal.length() + " artigos enviado ao cliente.");

                } catch (Exception e) {
                    System.err.println("❌ Erro no Servidor A: " + e.getMessage());
                }
            }
        }
    }

    /**
     * Um método auxiliar para conectar, enviar uma requisição e receber uma resposta
     * de um servidor trabalhador (B ou C).
     */
    private static JSONArray consultarServidor(String host, int porta, String requisicao) {
        // Garantir que o socket e os streams fechem sozinhos
        try (
            Socket socket = new Socket(host, porta);
            PrintWriter escritor = new PrintWriter(socket.getOutputStream(), true);
            BufferedReader leitor = new BufferedReader(new InputStreamReader(socket.getInputStream()))
        ) {
            // Envia a requisição para o servidor (B ou C)
            escritor.println(requisicao);
            // Lê a resposta
            String respostaJson = leitor.readLine();
            return new JSONArray(respostaJson);
        } catch (Exception e) {
            System.err.println("Falha ao comunicar com o servidor em " + host + ":" + porta + ". Retornando resultados vazios.");
            // Retorno de lista vazia, para não interromper o sistema
            return new JSONArray();
        }
    }
}