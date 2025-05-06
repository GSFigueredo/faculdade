package validador_cpf_thread_6;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        String diretorio_cpfs = "src/validador_cpfs/cpfs";
        String saidaTempo = "src/tempos_execucao/tempo_execucao_cod6.txt";

        File pasta = new File(diretorio_cpfs);
        File[] arquivos = pasta.listFiles((dir, name) -> name.endsWith(".txt"));
        if (arquivos == null || arquivos.length == 0) {
            System.out.println("Nenhum arquivo encontrado.");
            return;
        }

        Arrays.sort(arquivos);
        List<File> listaArquivos = Arrays.asList(arquivos);

        int size = listaArquivos.size();
        List<File> arquivos1 = listaArquivos.subList(0, size / 6);
        List<File> arquivos2 = listaArquivos.subList(size / 6, 2 * size / 6);
        List<File> arquivos3 = listaArquivos.subList(2 * size / 6, 3 * size / 6);
        List<File> arquivos4 = listaArquivos.subList(3 * size / 6, 4 * size / 6);
        List<File> arquivos5 = listaArquivos.subList(4 * size / 6, 5 * size / 6);
        List<File> arquivos6 = listaArquivos.subList(5 * size / 6, size);

        int[] resultado = new int[2];

        long inicio = System.currentTimeMillis();

        Thread t1 = new Thread(new ProcessarCPFS(arquivos1, resultado));
        Thread t2 = new Thread(new ProcessarCPFS(arquivos2, resultado));
        Thread t3 = new Thread(new ProcessarCPFS(arquivos3, resultado));
        Thread t4 = new Thread(new ProcessarCPFS(arquivos4, resultado));
        Thread t5 = new Thread(new ProcessarCPFS(arquivos5, resultado));
        Thread t6 = new Thread(new ProcessarCPFS(arquivos6, resultado));

        t1.start();
        t2.start();
        t3.start();
        t4.start();
        t5.start();
        t6.start();

        try {
            t1.join();
            t2.join();
            t3.join();
            t4.join();
            t5.join();
            t6.join();
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