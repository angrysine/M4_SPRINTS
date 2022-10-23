#include <iostream>
#include <string>
using namespace std;

// 1 -  Faça uma função que recebe uma certa medida e ajusta ela percentualmente 
// entre dois valores mínimo e máximo e retorna esse valor
double converteSensor(double medida,double min,double max); {
	/*
		podemos expressar a conversão do valor como uma 
		função de primeiro grau e igualamos os coeficientes lineares para
		obter a resposta abaixo
		*/
	return (1 - (max-medida)/(max-min))*100;
}
// 2 - Faça uma função que simule a leitura de um sensor lendo 
// valor do teclado ao final a função retorna este valor
string pergunta(string texto) {
	string resposta;
	cout<< texto;
	cin >> resposta;
	return cin;
}

// 3 - Faça uma função que armazena uma medida inteira qualquer 
// em um vetor fornecido. Note que como C não possui vetores 
// nativos da linguagem, lembre-se que você precisa passar o 
// valor máximo do vetor assim como a última posição preenchida
// Evite também que, por acidente, um valor seja escrito em 
// uma área de memória fora do vetor
 int armazenaValorVetor(int valor, int* vetor, int max, int posicao) {
		if (posicao < max) {         // verifica se a posição é válida
			vetor[posicao] = valor;  
			return posicao + 1;      
		}
		return posicao;  // retorna a posição atual se estamos no máximo
	}


// 4 - Faça uma função que recebe um vetor com 4 posições que contém 
// o valor da distância de um pequeno robô até cada um dos seus 4 lados.
// A função deve retornar duas informações: A primeira é a direção 
// de maior distância ("Direita", "Esquerda", "Frente", "Tras") e a 
// segunda é esta maior distância.
char* direcao(int* vetor, int* distancia) {
		int index = 0;//guardaremos a posição do maior elemento do vetor        
		int maior = vetor[0]; // armazena o maior atual

		//vamos percorrer a lista e atualizar o maior se acharmos um valor maior que o atual
		for (int i = 1; i < 4; i++) {
			if (vetor[i] > maior) {  
				maior = vetor[i];    
				index = i;          
			}
		}

		*distancia = maior;                                            
		return index < 4 ? direcoes[index] : (char*)"Nao encontrado";  
	}




// 5 - Faça uma função que pergunta ao usuário se ele deseja continuar o mapeamento e 
// retorna verdadeiro ou falso
bool leComando() {
	valor = pergunta("aperte 's' se deseja continuar 'n' se não")
	if (valor == "s") {
		return true;
	}
	else if (valor == "n") {
		return false;
	}
	else  {
		cout <<"não entendi";
		leComando();
	}
}


// 6 - A função abaixo (que está incompleta) vai "dirigindo" virtualmente um robô 
// e através de 4 sensores em cada um dos 4 pontos do robo ("Direita", "Esquerda", 
// "Frente", "Tras"). 
//      A cada passo, ele verifica as distâncias aos objetos e vai mapeando o terreno 
// para uma movimentação futura. 
//      Ele vai armazenando estas distancias em um vetor fornecido como parâmetro 
// e retorna a ultima posicao preenchida do vetor.
//      Esta função deve ir lendo os 4 sensores até que um comando de pare seja enviado 
//
//      Para simular os sensores e os comandos de pare, use as funções já construídas 
// nos ítens anteriores e em um looping contínuo até que um pedido de parada seja 
// enviado pelo usuário. 
//
//      Complete a função com a chamada das funções já criadas
int dirige(int *v,int maxv){
	int maxVetor = maxv;
	int *vetorMov = v;
	int posAtualVetor = 0;
	int dirigindo = 1;		
	while(dirigindo){		
		int medida = pergunta("ensira o valor da medida ")/// .. Chame a função de de leitura da medida para a "Direita"
		medida = converteSensor(medida,0,830);
		posAtualVetor =armazenaValorVetor(medida, vetorMov, maxVetor, posAtualVetor) // Chame a função para armazenar a medida no vetor
        ///////////////////////////////////////////////////////////////////////////		
		// Repita as chamadas acima para a "Esquerda", "Frente", "Tras"
	
		dirigindo = leComando();		
	}
	return posAtualVetor;
}


// O trecho abaixo irá utilizar as funções acima para ler os sensores e o movimento
// do robô e no final percorrer o vetor e mostrar o movimento a cada direção baseado 
// na maior distância a cada movimento
void percorre(int *v,int tamPercorrido){		
	int *vetorMov = v;
	int maiorDir = 0;
	
	for(int i = 0; i< tamPercorrido; i+=4){
		char *direcao = direcaoMenorCaminho(&(vetorMov[i]),&maiorDir);
		printf("Movimentando para %s distancia = %i\n",direcao,maiorDir);
	}
}

int main(int argc, char** argv) {
	int maxVetor = 100;
	int vetorMov[maxVetor*4];
	int posAtualVet = 0;
	
	posAtualVet = dirige(vetorMov,maxVetor);
	percorre(vetorMov,posAtualVet);
	
	return 0;
}