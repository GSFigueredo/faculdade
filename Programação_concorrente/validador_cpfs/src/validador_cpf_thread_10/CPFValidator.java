package validador_cpf_thread_10;

public class CPFValidator {
	public static boolean validaCPF(String cpf) {
		cpf = cpf.replaceAll("\\D", "");
		if (cpf.length() != 11 || cpf.chars().distinct().count() == 1) {
			return false;
		}
		
		for (int i = 9; i <= 10; i++) {
			int soma = 0;
			for (int j = 0; j < i; j++) {
			soma += (cpf.charAt(j) - '0') * ((i + 1) - j);
			}
			int digito = (soma * 10) % 11;
			if (digito == 10) digito = 0;
			if (digito != (cpf.charAt(i) - '0')) {
			return false;
			}
		}
		
		return true;
	}
}