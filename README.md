"# emprestimo" 

Versão (1.0.0):                                                                                         
	Solicitar as seguintes informações de um empréstimo de cliente: nome do cliente, CPF do cliente, data de realização do pedido do empréstimo, tipo do empréstimo (imóvel novo, reforma imóvel, carro, viagem, estudo), valor total do empréstimo, número de parcelas a serem pagas, juros mensal, quantidade de parcelas já pagas. Calcular o valor da parcela mensal (valor total do empréstimo / número de parcelas), aplicando os juros mensais).

Versão (1.0.1):
	Foi adicionado a exibição dos dados ao final do cadastro.

Versão (1.1.0):
	Foram adicionada novas funcionalidades, tais como:                                                             
	Incluir condicionais aninhados para indicar a situação do cliente no empréstimo (aprovado, aprovado após análise, reprovado). Se o valor da parcela mensal for menor/igual a 10% da renda mensal (nova informação solicitada) então o empréstimo está aprovado. Se o valor da parcela mensal for maior do que 30% da renda mensal então o empréstimo está reprovado. Se o valor da parcela mensal, for maior do que 10% e menor/igual a 30% então verifica se o cliente tem imóvel próprio quitado (nova informação solicitada) e nenhum empréstimo anterior em aberto (nova informação solicitada). Se sim então o empréstimo está aprovado após análise. Se não, o empréstimo está reprovado após análise.  Um empréstimo está quitado quando a quantidade de parcelas do empréstimo é igual a quantidade de parcelas pagas (assim, ao solicitar se há empréstimo anterior em aberto deve-se solicitar as duas quantidades de parcelas envolvidas e realizar o cálculo necessário). 