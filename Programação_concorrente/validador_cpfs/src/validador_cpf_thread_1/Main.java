package validador_cpf_thread_1;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        String diretorio_cpfs = "src/validador_cpfs/cpfs";
        String saidaTempo = "src/tempos_execucao/tempo_execucao_cod1.txt";

        File pasta = new File(diretorio_cpfs);
        File[] arquivos = pasta.listFiles((dir, name) -> name.endsWith(".txt"));
        if (arquivos == null || arquivos.length == 0) {
            System.out.println("Nenhum arquivo encontrado.");
            return;
        }

        Arrays.sort(arquivos);
        List<File> listaArquivos = Arrays.asList(arquivos);

        int[] resultado = new int[2];

        long inicio = System.currentTimeMillis();

        Thread t1 = new Thread(new ProcessarCPFS(listaArquivos, resultado));
        t1.start();

        try {
            t1.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        long fim = System.currentTimeMillis();

        System.out.println("CPFs válidos: " + resultado[0]);
        System.out.println("CPFs inválidos: " + resultado[1]);

        try (PrintWriter pw = new PrintWriter(saidaTempo)) {
            pw.println("Tempo total: " + (fim - inicio) + " ms");
            pw.println("CPFs válidos: " + resultado[0]);
            pw.println("CPFs inválidos: " + resultado[1]);
        } catch (IOException e) {
            System.out.println("Erro ao salvar resultado.");
            e.printStackTrace();
        }
    }
}
