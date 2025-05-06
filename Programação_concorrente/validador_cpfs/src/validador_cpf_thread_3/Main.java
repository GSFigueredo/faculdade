package validador_cpf_thread_3;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        String diretorio_cpfs = "src/validador_cpfs/cpfs";
        String saidaTempo = "src/tempos_execucao/tempo_execucao_cod3.txt";

        File pasta = new File(diretorio_cpfs);
        File[] arquivos = pasta.listFiles((dir, name) -> name.endsWith(".txt"));
        if (arquivos == null || arquivos.length == 0) {
            System.out.println("Nenhum arquivo encontrado.");
            return;
        }

        Arrays.sort(arquivos);
        List<File> listaArquivos = Arrays.asList(arquivos);

        // Dividir os arquivos em 3 partes
        List<File> arquivos1 = listaArquivos.subList(0, listaArquivos.size() / 3);
        List<File> arquivos2 = listaArquivos.subList(listaArquivos.size() / 3, 2 * listaArquivos.size() / 3);
        List<File> arquivos3 = listaArquivos.subList(2 * listaArquivos.size() / 3, listaArquivos.size());

        int[] resultado = new int[2];

        long inicio = System.currentTimeMillis();

        Thread t1 = new Thread(new ProcessarCPFS(arquivos1, resultado));
        Thread t2 = new Thread(new ProcessarCPFS(arquivos2, resultado));
        Thread t3 = new Thread(new ProcessarCPFS(arquivos3, resultado));

        t1.start();
        t2.start();
        t3.start();

        try {
            t1.join();
            t2.join();
            t3.join();
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
