//João Victor Alves da Silva 

#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* topo = NULL;

// headers
void menu();
void inicializar();
void pop();
void push();
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 4) {
		system("cls"); // somente no windows
		cout << "Menu Pilha";
		cout << endl << endl;
		cout << "1 - Inicializar Pilha \n";
		cout << "2 - Inserir elemento (Push) \n";
		cout << "3 - Remover elementos (Pop) \n";
		cout << "4 - Sair \n";


		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:push();
			break;
		case 3: pop();
			break;
		case 4:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{

	// se a lista já possuir elementos
	// libera a memoria ocupada
	NO* aux = topo;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	topo = NULL;
	cout << "Pilha inicializada \n";

}


void push() //Complemente a função PUSH para que ela inclua um elemento na pilha.
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;

	if (topo == NULL) {
		topo = novo;
		topo->prox = NULL;
	}

	else {
		novo->prox = topo;
		topo = novo;
	}
}

void pop() //Implemente a função POP que deve exibir e remover o ultimo elemento da pilha ou exibir "Pilha Vazia" se não houver nenhum elemento.
{
	//excluir
	if (topo == NULL) {
		cout << "Nao eh possivel excluir";
	}

	else {
		NO* aux = topo;
		aux->prox = aux;
		cout << "Valor excluido: " << aux->valor;
		free(topo);
		topo = aux;
	}
}


