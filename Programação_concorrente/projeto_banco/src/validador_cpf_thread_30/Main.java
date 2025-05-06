package validador_cpf_thread_30;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        String diretorio_cpfs = "src/validador_cpfs/cpfs";
        String saidaTempo = "src/tempos_execucao/tempo_execucao_cod30.txt";

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

        List<Thread> threads = new ArrayList<>();

        for (File arquivo : listaArquivos) {
            List<File> singletonList = Collections.singletonList(arquivo);
            Thread t = new Thread(new ProcessarCPFS(singletonList, resultado));
            threads.add(t);
            t.start();
        }

        for (Thread t : threads) {
            try {
                t.join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
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
