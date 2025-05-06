package validador_cpf_thread_15;

import java.io.*;
import java.util.List;

public class ProcessarCPFS implements Runnable {
    private List<File> arquivos;
    private int[] resultado; // 0 = válidos, 1 = inválidos

    public ProcessarCPFS(List<File> arquivos, int[] resultado) {
        this.arquivos = arquivos;
        this.resultado = resultado;
    }

    @Override
    public void run() {
        for (File arquivo : arquivos) {
            try (BufferedReader br = new BufferedReader(new FileReader(arquivo))) {
                String linha;
                while ((linha = br.readLine()) != null) {
                    boolean valido = CPFValidator.validaCPF(linha);
                    synchronized (resultado) {
                        if (valido) resultado[0]++;
                        else resultado[1]++;
                    }
                }
            } catch (IOException e) {
                System.out.println("Erro ao ler: " + arquivo.getName());
                e.printStackTrace();
            }
        }
    }
}
