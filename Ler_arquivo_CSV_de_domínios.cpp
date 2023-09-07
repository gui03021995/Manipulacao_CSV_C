/*

Acessar o site https://www.fakenamegenerator.com/ e gerar um set de dados com 1000 registros, escolhendo pelo menos 6 campos aleatórios.
Fazer o download do arquivo em formato EXCEL.
Estabelecer o layout apropriado para o set de dados que você gerou.
Gerar um novo arquivo CSV.
Criar uma STRUCT adequada para os registros do seu arquivo e executar a leitura desses registros conforme o modelo apresentado em aula.

DATA DA ENTREGA: 20/08/2021
    Serão enviados 3 (três) arquivos:
    o arquivo original dos dados utilizados, em Excel
    o arquivo convertido em CSV
    o código fonte CPP
    ATENÇÃO: O CÓDIGO FONTE DEVE APRESENTAR NAS SUAS PRIMEIRAS LINHAS O SEU NOME COMPLETO, EM COMENTÁRIO DE CÓDIGO

CRITÉRIOS DE AVALIAÇÃO:
    Construção adequada do set de dados CSV (10 pts)
    Construção elegante do código (identação, semântica das variáveis, comentários, código limpo) (10 pts)
    Código funcionando conforme a proposta (10 pts)
    Entrega dos arquivos no prazo estipulado (10 pts)


NOME: Guilherme Tadeu Gonçalves Morais

    LAYOUT DO ARQUIVO

    CAMPOS: Nome de Usuário;
            sexo;
            idade;
            pesoK;
            pais;
            infocc
            

    Número de registros: 1000
    Bytes no maior registro: 49
	Soma dos caracteres + ponto e vírgula (5) + \n (2)

*/

include <iostream>
//include <conio.c>


using namespace std;

include "FuncoesExternas.cpp"
#define TR 1000
#define MR 49

// DECLARAR STRUCT


typedef struct Arquivo
{
	char nomeUsuario;              //campos da Struct
    char sexo;
    int idade;
    float pesoK;
    char pais;
    char infocc;
};

Arquivo Registros[TR];

void lerDados();
void consultarDados();

int main()
{
    setlocale(LC_ALL,"");
    int opcao, vetor[TR];

    do
    {
        system("cls");
        cout << "1 - LER DADOS DO ARQUIVO\n";
        cout << "2 - CONSULTAR DADOS\n";
        cout << "0 - SAIR DO PROGRAMA\n\n";
        cout << "OPÇÃO: ";
        cin >> opcao;
        switch(opcao)
        {
            case 1:  lerDados();break;
            case 2:  consultarDados();break;
            case 0:  cout << "FINALIZANDO...\n";break;
            default: cout << "OPÇÃO INVÁLIDA. TENTE NOVAMENTE\n";
                     system("pause>null");
        }
    }while(opcao);

    system("pause");
    return 0;
}

void lerDados()
{
    titulo("\n LENDO OS DADOS EXISTENTES NO ARQUIVO CSV\n ");

    int i, j, campo;
    char acumular;
    char linha[MR];  //maior registro em uma linha no arquivo (103)

    j = 0;        //será o índice do vetor
    campo = 0;        //será o contador dos campos da struct

    // abrir o arquivo com os registros em texto (CSV)
    FILE *arquivo;
    arquivo = fopen("FakeNameGenerator.com_8d2bd7af.csv","r");  // r = read , leitura

    while(!feof(arquivo))
    {
    	fgets(linha,MR,arquivo);
    	cout << linha << "\n";
    	j++;
    	campo = 0;
    	acumular = '';
	}
	system("pause");
	// NÃO esquecer de fechar o arquivo
	fclose(arquivo);
}

void consultarDados()
{

    titulo("CONSULTAR DADOS");
    int consulta;

    cout << "CHAVE PARA CONSULTA: ";
    cin >> consulta;
    
    cout << "=====================================\n";
    cout << "REGISTRO NÚMERO........:"  << consulta << "\n";
    cout << "Nome do usuário .......:" << Registros[consulta].nomeUsuario << "\n";
    cout << "Sexo...................:" << Registros[consulta].sexo << "\n";
    cout << "Idade do usuário ......:" << Registros[consulta].idade << "\n";
    cout << "Peso do usuário........:" << Registros[consulta].pesoK << "\n";
    cout << "Bandeira do cartao ....:" << Registros[consulta].infocc << "\n";
    cout << "=====================================\n";
    system("pause");

}

