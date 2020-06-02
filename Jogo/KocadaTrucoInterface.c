#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<time.h>

// constantes
#define autor   "Marcio Jose de Sousa"
#define email   "cocada120@hotmail.com"
#define normal  1
#define truco   3
#define pseis   6
#define pnove   9
#define pdoze  12

// variaveis globais
char lixo, nome[13];
int  carta[6], jogjogo, jogponto, jogqueda, kocjogo, kocponto, kocqueda;
bool pebar;

// prototipos de fun��o, ordem tamanho do nome recebido
void logo();
void linha();
void sobre();
void jogJogou();
void embaralha();
void tela(bool bar);
void mostraBaralho();
int  escolhaJogador();
void kocCarta(bool c);
void linha_tela_5e_7();
void kocadaJogou(int z);
void linha_tela_1_a_10();
void jogadorJogou(int z);
void chat_mostraCarta(int w);
void mulprint(int ch, int tam);
int  mostraCarta(int x, bool z);
void mostraTurno(int turno, int z);
char escolhe( int x, bool z, bool ja, bool jb, bool jc, bool truc);

// o jogo.
int main(){
	logo();
	char opcao='a';
	printf(" Maximo de 12 caracteres.\n");
	printf(" Escreva seu nome: ");
	scanf ("%s%c", &nome, &lixo);
	printf("\n Bem vindo! ao game Kocada Truco: %s \n\n", nome);
	while(opcao!='0'){
		printf( "                    1. Jogar com Ponta do baralho: (4 %c ao 10 %c)\n"
				"                    2. Jogar com Pe do baralho   : (J %c ao  4 %c)\n"
				"                    3. Ver baralho\n"
				"                    4. Sobre\n"
				"                    0. Sair\n", 6,5,4,5);
		printf(" Escolha a partir do numero: ");
		scanf("%c%c", &opcao, &lixo); 
		puts("\n");
		(opcao<'0' || opcao>'4') ? printf(" digite uma opcao valida!\n\n"):
		opcao=='0' ? exit(0):
		opcao=='1' ? tela(false):
		opcao=='2' ? tela(true):
		opcao=='3' ? mostraBaralho():
		opcao=='4' ? sobre(): NULL;
	}
	return 0;
}
void tela(bool bar){
	bar==true ? (pebar= true) : (pebar= false);
	/* cfj= carta foi jogada, "k e koc" referencia ao pc, "j e jog" referencia ao jogador,
	pt= pontos, epa= existe possibilidade de aumentar */
	bool aceitou, cfj1, cfj2, cfj3, epa, fala, fim, jogo, jogador, jogAumentou, jogCorreu, kmostra1;
	bool kmostra2, kmostra3, kocCorreu, pcTrucou, pcQtrucou, pcQtrucou_turno1, primeira, responde;
	char escolheu, str1[30], str2[30], str3[30], str4[30], str5[30], vez;
	int  a, b, c, d, e, f, a1, b1, c1, d1, e1, f1, A, B, C, D, E, F, x, x1, x2, x3, y, y1, y2, y3;
	int  empatou, jjogou1, jjogou2, jjogou3, kjogou1, kjogou2, kjogou3, maior, medio, menor;
	int  pt, recebe, salto1, salto2, salto3, salto4, soma, turno, venceu;
	int  venceuTurno_1, venceuTurno_2, venceuTurno_3, xchat1, xchat2, xchat3, xchat4, xchat5;
	
	// inicializando variaveis
	jogo= true;
	jogjogo = jogponto = jogqueda = kocjogo = kocponto = kocqueda = 0;
	recebe = escolhaJogador();
	recebe==1 ? (jogador= true) : (jogador= false);
	strcpy(str1, "                              ");
	strcpy(str2, "                              ");
	strcpy(str3, "                              ");
	strcpy(str4, "                              ");
	strcpy(str5, "                              ");
	xchat1 = xchat2 = xchat3 = xchat4 = xchat5 = -9;
	while(jogo==true){
		inicio:
		jogador==true ? (vez= 'j') : (vez= 'k');
		// inicializando variaveis
		turno = 1;
		pt = normal;
		primeira = NULL;
		jjogou1 = jjogou2 = jjogou3 = kjogou1 = kjogou2 = kjogou3 = venceu = 0;
		empatou = maior = medio = menor = salto1 = salto2  = salto3 = salto4 = soma = 0;
		venceuTurno_1 = venceuTurno_2 = venceuTurno_3 =  0;
		epa = true;
		aceitou = cfj1 = cfj2 = cfj3 = fim = jogAumentou = jogCorreu = kocCorreu = responde = false;
		kmostra1 = kmostra2 = kmostra3 = pcTrucou = pcQtrucou = pcQtrucou_turno1 = false;
		// x1, x2, x3, y1, y2, y3 recebe o valor das cartas dos jogadores
		x = x1 = x2 = x3 = y = y1 = y2 = y3 = 0;
		embaralha();
		//a,b,c,d,e,f, recebe numero aleatorio da carta
		a= carta[0], b= carta[1], c= carta[2], d= carta[3], e= carta[4], f= carta[5];
		//a1,b1,c1,d1,e1,f1 recebe o codigo da carta
		a1= mostraCarta(a, false); b1= mostraCarta(b, false); c1= mostraCarta(c, false);
		d1= mostraCarta(d, false); e1= mostraCarta(e, false); f1= mostraCarta(f, false);
		//A,B,C,D,E,F recebe valor da carta
		A= a1/10; B= b1/10; C= c1/10; D= d1/10; E= e1/10; F= f1/10;
		if(jogponto== 11 || kocponto== 11){
			pt = truco;
			epa= false;
		}
		jogador==true ? strcpy(str1, " Jogador comeca:              ")&&(fala=true):
						strcpy(str1, " Kocada comeca:               ")&&(fala=true);
		if(fala==true) goto fala;
		while(fim==false){
			{//escopo tela
				linha_tela_1_a_10();
				{//linha 11
				printf("%c", 186);  mulprint(  0, 19); printf("%c", 179);
					   mostraTurno( 1, venceuTurno_1); printf("%c", 179);
									mulprint(  0, 18); printf("%c", 186);
				}{//linha 12
				printf("%c", 186);  printf(" 1. "); cfj1==false ? mostraCarta(a, true) : jogJogou();
									printf("   %c", 179);  mulprint(  0, 3);
									jogadorJogou(jjogou1); printf("    X    ");
									kocadaJogou(kjogou1);  mulprint(  0, 3);
				printf("%c", 179);	printf(" 1. "); kocCarta(kmostra1); printf("%c", 186);
				}{//linha 13
				printf("%c", 186);  mulprint(  0, 19); printf("%c", 179);
					   mostraTurno( 2, venceuTurno_2); printf("%c", 179);
									mulprint(  0, 18); printf("%c", 186);
				}{//linha 14
				printf("%c", 186);  printf(" 2. "); cfj2==false ? mostraCarta(b, true) : jogJogou();
									printf("   %c", 179);  mulprint(  0, 3);
									jogadorJogou(jjogou2); printf("    X    ");
									kocadaJogou(kjogou2);  mulprint(  0, 3);
				printf("%c", 179);	printf(" 2. "); kocCarta(kmostra2);  printf("%c", 186);
				}{//linha 15
				printf("%c", 186);  mulprint(  0, 19); printf("%c", 179);
					   mostraTurno( 3, venceuTurno_3); printf("%c", 179);
									mulprint(  0, 18); printf("%c", 186);
				}{//linha 16
				printf("%c", 186);  printf(" 3. "); cfj3==false ? mostraCarta(c, true) : jogJogou();
									printf("   %c", 179);  mulprint(  0, 3);
									jogadorJogou(jjogou3); printf("    X    ");
									kocadaJogou(kjogou3);  mulprint(  0, 3);
				printf("%c", 179);	printf(" 3. "); kocCarta(kmostra3);  printf("%c", 186);
				}{//linha 17
				printf("%c", 204);  mulprint( 205, 19); printf("%c", 216);
									mulprint( 205, 19); printf("%c", 205);
									mulprint( 205, 19); printf("%c", 207);
									mulprint( 205, 18); printf("%c", 185);
				}{//linha 18
				printf("%c", 186);  mulprint( 176, 11); printf(" chat   "); printf("%c", 179);
									printf("1. %s",str2);
									if(strlen(str2)==18) chat_mostraCarta(xchat2);
									mulprint(   0, 25); printf("%c", 186);
				}{//linha 19
				printf("%c", 186);  mulprint( 176, 19); printf("%c", 179);
									printf("2. %s",str3);
									if(strlen(str3)==18) chat_mostraCarta(xchat3);
									mulprint(   0, 25); printf("%c", 186);
				}{//linha 20
				printf("%c", 186);  mulprint( 176, 19); printf("%c", 179);
									printf("3. %s",str4);
									if(strlen(str4)==18) chat_mostraCarta(xchat4);
									mulprint(   0, 25); printf("%c", 186);
				}{//linha 21
				printf("%c", 186);  mulprint( 176, 19); printf("%c", 179);
									printf("4. %s",str5);
									if(strlen(str5)==18) chat_mostraCarta(xchat5);
									mulprint(   0, 25); printf("%c", 186);
				}{//linha 22
				printf("%c", 200);  mulprint( 205, 19); printf("%c", 207);
									mulprint( 205, 58); printf("%c", 188);
				}
			}//escopo tela
			if(vez=='j'){//vez do jogador
				if(pcTrucou==true){
					escolheu= escolhe( pt, epa, cfj1, cfj2, cfj3, pcTrucou);
					if(escolheu=='1'||escolheu=='2'||escolheu=='3'){
						strcpy(str1, " Jogador Aceitou              ");
						pcTrucou= false; aceitou= true; goto Aceittou;
					}
					else if(escolheu=='4') goto escolha_4;
					else if(escolheu=='5') goto escolha_5;
				}
				else if (turno==1 && x1==0){
					escolheu= escolhe( pt, epa, cfj1, cfj2, cfj3, false);
					escolheu=='1' ? (x1=A)&&(cfj1= true)&&(jjogou1= a1)&&(xchat1=a):
					escolheu=='2' ? (x1=B)&&(cfj2= true)&&(jjogou1= b1)&&(xchat1=b):
					escolheu=='3' ? (x1=C)&&(cfj3= true)&&(jjogou1= c1)&&(xchat1=c):0;
				}
				else if (turno==2 && x2==0){
					escolheu= escolhe( pt, epa, cfj1, cfj2, cfj3, false);
					escolheu=='1' ? (x2=A)&&(cfj1= true)&&(jjogou2= a1)&&(xchat1=a):
					escolheu=='2' ? (x2=B)&&(cfj2= true)&&(jjogou2= b1)&&(xchat1=b):
					escolheu=='3' ? (x2=C)&&(cfj3= true)&&(jjogou2= c1)&&(xchat1=c):0;
				}
				else if (turno==3 && x3==0){
					escolheu= escolhe( pt, epa, cfj1, cfj2, cfj3, false);
					escolheu=='1' ? (x3=A)&&(cfj1= true)&&(jjogou3= a1)&&(xchat1=a):
					escolheu=='2' ? (x3=B)&&(cfj2= true)&&(jjogou3= b1)&&(xchat1=b):
					escolheu=='3' ? (x3=C)&&(cfj3= true)&&(jjogou3= c1)&&(xchat1=c):0;
				}
				if(escolheu=='1'||escolheu=='2'||escolheu=='3'){
					strcpy(str1, " Jogador jogou:   ");
				}
				else if(escolheu=='4') {
					escolha_4:
					jogCorreu= true; goto correu;
				}
				else if(escolheu=='5') {
					escolha_5:	
					epa= false;
					if(pt==normal) {
						strcpy(str1, " Jogador trucou:              ");
						jogAumentou= true; pt= truco;
					}
					else if(pt==truco){
						strcpy(str1, " Jogador pediu seis:          ");
						jogAumentou= true; pcTrucou= false; pt= pseis;
					}
					else if(pt==pseis){
						strcpy(str1, " Jogador pediu nove:          ");
						jogAumentou= true; pcTrucou= false; pt= pnove;
					}
					else if(pt==pnove){
						strcpy(str1, " Jogador pediu doze:          ");
						jogAumentou= true; pcTrucou= false; pt= pdoze;
					}
				}
				Aceittou:
				vez='k';
			}else if(vez=='k'){//vez do pc
				if(turno==1) soma= D+E+F;
				else if(turno==2) soma= D+E+F-(kjogou1/10);
				else if(turno==3) soma= D+E+F-(kjogou1/10)-(kjogou2/10);
				if(jogAumentou==true) { responde=true; goto responde; }
				if (turno==1 && y1==0){
					if(soma<16) { kocCorreu= true; goto correu;	}
					else if(jogponto==11 && kocponto==11) goto joga;
					else if(kocponto==11 && soma<28) { kocCorreu= true; goto correu;	}
					if(soma>27 && pt==normal && jogponto!=11 && kocponto!=11){
						epa= true; vez='j';pt=truco;
						strcpy(str1, " Kocada trucou:               ");
						pcQtrucou_turno1=true; pcQtrucou=true;
						pcTrucou=true; goto fala;
					}
					joga:
					menor=d1;
					if(e1<menor) menor=e1;
					if(f1<menor) menor=f1;
					maior=d1;
					if(e1>maior) maior=e1;
					if(f1>maior) maior=f1;
					medio= d1+e1+f1-maior-menor;
					if(medio==d1) medio=d1;
					else if(medio==e1) medio=e1;
					else if(medio==f1) medio=f1;
					if(x1>0){
						if     (menor/10>x1) y=menor;
						else if(medio/10>x1) y=medio;
						else if(maior/10>x1) y=maior;
						else y=menor;
					}else{
						if(soma<24) y=maior;
						else if(soma<30) y=medio;
						else y=menor;
					}
					strcpy(str1, " Kocada jogou:    ");
					y==d1 ? (y1=D)&&(kjogou1=d1)&&(kmostra1=true)&&(xchat1=d) :
					y==e1 ? (y1=E)&&(kjogou1=e1)&&(kmostra2=true)&&(xchat1=e) :
					y==f1 ? (y1=F)&&(kjogou1=f1)&&(kmostra3=true)&&(xchat1=f) :0;
					pcQtrucou= false;
					vez='j';
				}//turno 1
				else if (turno==2 && y2==0){
					if(jogAumentou==true) { responde=true; goto responde; }
					if(empatou==1){
						(kjogou1==d1)&&(e1>f1) ? (y=e1) :
						(kjogou1==d1)&&(e1<f1) ? (y=f1) :
						(kjogou1==e1)&&(d1>f1) ? (y=d1) :
						(kjogou1==e1)&&(d1<f1) ? (y=f1) :
						(kjogou1==f1)&&(d1>e1) ? (y=d1) :
						(kjogou1==f1)&&(d1<e1) ? (y=e1) :0;
					}
					else if(primeira==true){
						(kjogou1==d1)&&(e1<f1) ? (y=e1) :
						(kjogou1==d1)&&(e1>f1) ? (y=f1) :
						(kjogou1==e1)&&(d1<f1) ? (y=d1) :
						(kjogou1==e1)&&(d1>f1) ? (y=f1) :
						(kjogou1==f1)&&(d1<e1) ? (y=d1) :
						(kjogou1==f1)&&(d1>e1) ? (y=e1) :0;
					}
					else{ x=jjogou2/10;
						(kjogou1==d1)&&(E>x)&&(F<=x) ?        (y=e1) :
						(kjogou1==d1)&&(F>x)&&(E<=x) ?        (y=f1) :
						(kjogou1==d1)&&(E>x&&F>=x)&&(e1<f1) ? (y=e1) :
						(kjogou1==d1)&&(E>=x&&F>x)&&(f1<e1) ? (y=f1) :
						(kjogou1==d1)&&(E<=x&&F<=x)&&(e1<f1)? (y=e1) :
						(kjogou1==d1)&&(E<=x&&F<=x)&&(f1<e1)? (y=f1) :
						(kjogou1==e1)&&(D>x)&&(F<=x) ?        (y=d1) :
						(kjogou1==e1)&&(F>x)&&(D<=x) ?        (y=f1) :
						(kjogou1==e1)&&(D>x&&F>=x)&&(d1<f1) ? (y=d1) :
						(kjogou1==e1)&&(D>=x&&F>x)&&(f1<d1) ? (y=f1) :
						(kjogou1==e1)&&(D<=x&&F<=x)&&(d1<f1)? (y=d1) :
						(kjogou1==e1)&&(D<=x&&F<=x)&&(f1<d1)? (y=f1) :
						(kjogou1==f1)&&(D>x)&&(E<=x) ?        (y=d1) :
						(kjogou1==f1)&&(E>x)&&(D<=x) ?        (y=e1) :
						(kjogou1==f1)&&(D>x&&E>=x)&&(d1<e1) ? (y=d1) :
						(kjogou1==f1)&&(D>=x&&E>x)&&(e1<d1) ? (y=e1) :
						(kjogou1==f1)&&(D<=x&&E<=x)&&(d1<e1)? (y=d1) :
						(kjogou1==f1)&&(D<=x&&E<=x)&&(e1<d1)? (y=e1) :0;
					}
					strcpy(str1, " Kocada jogou:    ");
					y==d1 ? (y2=D)&&(kjogou2=d1)&&(kmostra1=true)&&(xchat1=d) :
					y==e1 ? (y2=E)&&(kjogou2=e1)&&(kmostra2=true)&&(xchat1=e) :
					y==f1 ? (y2=F)&&(kjogou2=f1)&&(kmostra3=true)&&(xchat1=f) :0;
					vez='j';
				}//turno 2
				else if (turno==3 && y3==0){
					if(jogAumentou==true) { responde=true; goto responde; }
					x=jjogou3/10;
					(kjogou1==d1)&&(kjogou2==e1) ? (y=f1) :
					(kjogou2==d1)&&(kjogou1==e1) ? (y=f1) :
					(kjogou1==d1)&&(kjogou2==f1) ? (y=e1) :
					(kjogou2==d1)&&(kjogou1==f1) ? (y=e1) :
					(kjogou1==e1)&&(kjogou2==f1) ? (y=d1) :
					(kjogou2==e1)&&(kjogou1==f1) ? (y=d1) :0;
					y==d1 ? y3=D: y==e1 ? y3=E : y==f1 ? y3=F: 0;
					if(x3>0 && y3>x && pt==truco && pcQtrucou_turno1==false && jogponto!=11 && kocponto!=11){
						pt=pseis; epa= true; vez='j';
						strcpy(str1, " Kocada pediu seis:           ");
						y3=0; pcQtrucou=true; pcTrucou=true; goto fala;
					}else if(x3>0 && y3>x && pt==normal && jogponto!=11 && kocponto!=11){
						pt=truco; epa= true; vez='j';
						strcpy(str1, " Kocada trucou:               ");
						y3=0; pcQtrucou_turno1=true;
						pcQtrucou=true; pcTrucou=true; goto fala;
					}else{
						strcpy(str1, " Kocada jogou:    ");
						y==d1 ? (y3=D)&&(kjogou3=d1)&&(kmostra1=true)&&(xchat1=d) :
						y==e1 ? (y3=E)&&(kjogou3=e1)&&(kmostra2=true)&&(xchat1=e) :
						y==f1 ? (y3=F)&&(kjogou3=f1)&&(kmostra3=true)&&(xchat1=f) :0;
					}
					vez='j';
				}//turno 3
				responde:
					{
						if(responde==true){
							responde= false; jogAumentou= false; vez='j';
							if(turno==1){
								if(pt==pnove && soma>31){
									pt=pdoze; aceitou= true;
									strcpy(str1, " Kocada Aceitou               ");
								}else if(pt==pnove && soma>31){
									pt=pdoze;
									strcpy(str1, " Kocada pediu doze:           ");
								}else if(pt==pseis && soma>31){
									pcTrucou= true; pt=pnove; epa= true;
									strcpy(str1, " Kocada pediu nove:           ");
								}else if(pt==truco&&soma>27&&((D>=9&&E>=9)||(D>=9&&F>=9)||(E>=9&&F>=9))){
									strcpy(str1, " Kocada pediu seis:           ");
									 pcTrucou= true; epa= true; pt=pseis;
								}else if(soma>21&&((D>=8&&E>=8)||(D>=8&&F>=8)||(E>=8&&F>=8))){
									if(pcQtrucou==true) vez='k'; aceitou= true;
									strcpy(str1, " Kocada Aceitou               ");
								}else{
									kocCorreu= true; goto correu;
								}
							}
							else if(turno==2){
								if(pt==pdoze && soma>=24){
									pt=pdoze; aceitou= true;
									strcpy(str1, " Kocada Aceitou               ");
								}else if(pt==pnove && soma>=24){
									pcTrucou= true; pt=pdoze;
									strcpy(str1, " Kocada pediu doze:           ");
								}else if(pt==pseis && soma>=24){
									pcTrucou= true; pt=pnove; epa= true;
									strcpy(str1, " Kocada pediu nove:           ");
								}else if(pt==truco&&soma>=22){
									pcTrucou= true; pt=pseis; epa= true; 
									strcpy(str1, " Kocada pediu seis:           ");
								}else if(soma>=18){
									if(pcQtrucou==true) vez='k'; aceitou= true;
									strcpy(str1, " Kocada Aceitou               ");
								}else if(soma>=16 && primeira==true){
									if(pcQtrucou==true) vez='k'; aceitou= true;
									strcpy(str1, " Kocada Aceitou               ");
								}else{
									kocCorreu= true; goto correu;
								}
							}
							else if(turno==3){
								if(pt==pdoze && soma==14){
									pt=pdoze; aceitou= true;
									strcpy(str1, " Kocada Aceitou               ");
								}else if(pt==pnove && soma==14){
									pcTrucou= true; pt=pdoze;
									strcpy(str1, " Kocada pediu doze:           ");
								}else if(pt==pseis && soma==14){
									pcTrucou= true; pt=pnove; epa= true;
									strcpy(str1, " Kocada pediu nove:           ");
								}else if(pt==truco&&soma==14){
									pcTrucou= true; pt=pseis; epa= true; 
									strcpy(str1, " Kocada pediu seis:           ");
								}else if(soma>=8 || pt==pdoze){
									if(pcQtrucou==true) vez='k'; aceitou= true;
									strcpy(str1, " Kocada Aceitou               ");
								}else{
									kocCorreu= true; goto correu;
								}
							}
						}// fim if responde
					}// fim bloco responde
			}// fim vez pc
			if (turno==1 && x1>0 && y1>0 && salto1==1){
				if (x1==y1){
					strcpy(str1, " Turno empatado mao da maior  ");
					empatou=1; y=0;
					jogador==true ? vez= 'j' : 'k';
				}
				else if (x1>y1){
					strcpy(str1, " Jogador venceu este turno    ");
					venceuTurno_1=1;
					primeira=false; y=0; vez = 'j';
				}
				else if (x1<y1){
					strcpy(str1, " Kocada venceu este turno     ");
					venceuTurno_1=2;
					primeira=true; y=0; vez = 'k';
				}
				salto1=0;
				turno=2;
			}
			else if (turno==2 && x2>0 && y2>0 && salto2==1){
				if (empatou==1){
					if (x2==y2){
						empatou=2; y=0; turno=3;
						jogador==true ? vez= 'j' : 'k';
						strcpy(str1, " Turno empatado mao da maior  ");
					}
					else if (x2>y2) {venceuTurno_2=1; goto jogVenceuTurno_Rodada;}
					else if (x2<y2) {venceuTurno_2=2; goto kocVenceuTurno_Rodada;
					}
				}
				else if (x2==y2) {
					if(primeira==false){
						venceuTurno_2=1;
						strcpy(str4, str3);
						strcpy(str3, str2);
						strcpy(str2, " Turno empatado Jogador venceu");
						strcpy(str1, " Jogador venceu esta rodada   ");
						venceu= 1; turno=0;
					}
					else{
						venceuTurno_2=2;
						strcpy(str4, str3);
						strcpy(str3, str2);
						strcpy(str2, " Turno empatado Kocada venceu ");
						strcpy(str1, " Kocada venceu esta rodada    ");
						venceu= -1; turno=0;
					}
				}
				else if (x2>y2 ) {
					if(primeira==false)	{venceuTurno_2=1; goto jogVenceuTurno_Rodada;}
					else{
						venceuTurno_2=1;
						strcpy(str1, " Jogador venceu este turno    ");
						y=0; vez='j'; turno=3;
					}
				}
				else if (x2<y2 ) {
					if(primeira==true) {venceuTurno_2=2; goto kocVenceuTurno_Rodada;}
					else{
						venceuTurno_2=2;
						strcpy(str1, " kocada venceu este turno     ");
						y=0; vez='k'; turno=3;
					}
				}
				salto2=0;
			}
			else if (turno==3 && x3>0 && y3>0 && salto3==1){
				if(empatou==2){
					if (x3==y3){
						strcpy(str4, str3);
						strcpy(str3, str2);
						strcpy(str2, " Rodada empatou ninguem venceu");
						strcpy(str1, " PROXIMA RODADA               ");
						venceu= 0;fim=true;
					}
					else if (x3>y3)	{venceuTurno_3=1; goto jogVenceuTurno_Rodada;}
					else if (x3<y3) {venceuTurno_3=2; goto kocVenceuTurno_Rodada;}
				}
				else if (x3==y3){
					if(primeira==false) {venceuTurno_3=1; goto jogVenceuTurno_Rodada;}
					else {venceuTurno_3=2; goto kocVenceuTurno_Rodada;}
				}  
				else if (x3>y3)	{venceuTurno_3=1; goto jogVenceuTurno_Rodada;}
				else if (x3<y3) {venceuTurno_3=2; goto kocVenceuTurno_Rodada;}
			}
			if(x==999){
				jogVenceuTurno_Rodada:
					{
						strcpy(str4, str3);
						strcpy(str3, str2);
						strcpy(str2, " Jogador venceu este turno    ");
						strcpy(str1, " Jogador venceu esta rodada   ");
						venceu= 1; turno=0;
						goto fala;
					}
			}
			if(x==998){
				kocVenceuTurno_Rodada:
					{
						strcpy(str4, str3);
						strcpy(str3, str2);
						strcpy(str2, " kocada venceu este turno     ");
						strcpy(str1, " kocada venceu esta rodada    ");
						venceu= -1; turno=0;
						goto fala;
					}
			}	
			correu:
				{
					if (jogCorreu==true){ jogCorreu= false;
						if(jogponto==11 && turno==2) aceitou= true;
						{
							     if(pt==truco && aceitou==true) pt= truco;
							else if(pt==pseis && aceitou==true) pt= pseis;
							else if(pt==pnove && aceitou==true) pt= pnove;
							else if(pt==pdoze && aceitou==true) pt= pdoze;
							else if(pt==truco) pt= normal;
							else if(pt==pseis) pt= truco;
							else if(pt==pnove) pt= pseis;
							else if(pt==pdoze) pt= pnove;
							strcpy(str1, " Jogador correu:              ");
							venceu = -1; vez='a';
						}
					}				
					if (kocCorreu==true){ kocCorreu= false;
						{
							     if(pt==truco) pt= normal;
							else if(pt==pseis) pt= truco;
							else if(pt==pnove) pt= pseis;
							else if(pt==pdoze) pt= pnove;
							strcpy(str1, " Kocada correu:               ");
							venceu = 1; vez='a';
						}
					}
				}// correu
			fala:
			if(salto4==1) fim= true;
			if(venceu==1 || venceu==-1) salto4++;
			if(x1>0&&y1>0) salto1++;
			if(x2>0&&y2>0) salto2++;
			if(x3>0&&y3>0) salto3++;
			xchat5=xchat4;
			xchat4=xchat3;
			xchat3=xchat2;
			xchat2=xchat1;
			strcpy(str5, str4);
			strcpy(str4, str3);
			strcpy(str3, str2);
			strcpy(str2, str1);
			if(salto4==1){
				strcpy(str1, " PROXIMA RODADA               ");
				xchat5=xchat4;
				xchat4=xchat3;
				xchat3=xchat2;
			}
			system("pause");
		}//while fim
		final:
		venceu ==  1 ? (jogponto += pt) :
		venceu == -1 ? (kocponto += pt) :0;
		jogador== true ? (jogador= false) : (jogador= true);
		if( jogponto>=12 || kocponto>=12){
			jogo = false;
			if( kocponto>=12){
				strcpy(str2, " Kocada venceu o jogo         ");
				kocjogo += 1;
				printf(" Kocada venceu o jogo         ");
			}
			if( jogponto>=12){
				strcpy(str2, " Jogador venceu o jogo        ");
				jogjogo += 1;
				printf(" Jogador venceu o jogo        ");
			}
			if(jogjogo==2){
				jogqueda++;
				jogjogo=0;
				kocjogo=0;
			}
			if(kocjogo==2){
				kocqueda++;
				jogjogo=0;
				kocjogo=0;
			}
			char resp;
			printf("\a\a\a");
			printf("\n Quer continuar aperte 's': ");
			scanf("%c%c", &resp, &lixo);
			puts("\n");
			if(resp=='s'){
				jogo = true;
				jogponto= 0; kocponto= 0;
				goto inicio;
			}else exit(0);
		}
	}//while jogo
}//tela function
void logo(){
	int i;
	linha();
	printf("%30c", 201);
	for(i=0; i<18; i++)	printf("%c", 205);
	printf("%c\n", 187);
	printf("%30c   Kocada Truco   %c\n", 186, 186);
	printf("%30c    %c  %c  %c  %c    %c\n", 186, 5, 3, 6, 4, 186);
	printf("%30c", 200);
	for(i=0; i<18; i++)	printf("%c", 205);
	printf("%c\n", 188);
	linha();
}
void linha(){
	printf("********************************************************************************\n");
}
void sobre(){
	printf( "\tGamemania: Kocada Truco\n"
			"\t    Autor: %s\n"
			"\t   e-mail: %s\n"
			"\t  Empresa: MKG - Marcio Kocada Games\n"
			"\t   Versao: 2.0\n"
			"\t   Estilo: Cartas\n\n"
			"\tlicenciado por jogue o quanto quiser\n", autor, email);
	linha();
}
void jogJogou(){
	printf(" %c%c", 91,93);
	mulprint( 0, 9);
}
void embaralha(){
	int i, j, cont;
	srand(time(NULL));
	// fornece numeros aleatorios sem repeti�ao, as cartas de 0-27
	for (i=0; i<6; i++){
		carta[i]= rand() % 28;
	}
	// verifica cartas repetidas
	do{
		cont=0;
		for (i=0; i<6; i++){
			for (j=i+1; j<6; j++){
				if( carta[i] == carta[j] ){
					carta[i] = rand() % 28;
					cont++;
					break;
				}
			}
		}
	}while(cont>0);
}
void mostraBaralho(){
	char a;
	int  i=1;
	bool p=false;
	while(i==1){
		printf(" Ponta do baralho (1) | pe do baralho (2)\n");
		scanf("%c%c", &a, &lixo);
		(a<'1' || a>'2')? (i=1)&&printf(" ! numero invalido\n"):
		(a=='1') ? (p=true)&&(i=0):	
		(a=='2') ? (i=0):0;	
	}
	if(p==true){
		printf(" Ponta do baralho\n");
		pebar= false;
		for(i=0; i<28; i++){
			printf(" ");
			mostraCarta(i, true);
			if(i==2 || i==6 || i==10 || i==14 || i==18 || i==22) printf("\n");
			else i<22 ? printf("\t"): printf("\n");
		}
	}
	else{
		printf(" Pe do baralho\n");
		pebar= true;
		for(i=0; i<28; i++){
			printf(" ");
			mostraCarta(i, true);
			if(i==3 || i==7 || i==11 || i==14 || i==18 || i==22) printf("\n");
			else if(i==12) printf("\t\t\t");
			else i<22 ? printf("\t"): printf("\n");
		}
	}
	puts("\n");
	linha();
}
int escolhaJogador(){
	char x;
	int  i=1, k;
	while(i!=0){
		printf( " Escolha quem comeca: \n\n"
				"1. %s comeca\n"
				"2. Kocada comeca\n", nome);
		scanf("%c%c", &x, &lixo);
		(x<='0' || x>='3')? (i=1) && printf(" ! numero invalido\n\n"):
		(x=='1')? ((k= 1) && (i=0)):
		(x=='2')? ((k= 2) && (i=0)):0;
		puts("\n");	
	}
	return k;
}
void kocCarta(bool c){
	c== false ? printf(" %2c", 178) : printf(" %c%c", 91,93);
	mulprint( 0, 11);
}
void linha_tela_5e_7(){
	{//linha 5 e 7
	printf("%c", 199);  mulprint( 196, 19); printf("%c", 197);
						mulprint( 196, 19); printf("%c", 197);
						mulprint( 196, 19); printf("%c", 197);
						mulprint( 196, 18); printf("%c", 182);
	}
}
void kocadaJogou(int z){
	int d, e, f, d1, e1, f1;
	d = carta[3]; e = carta[4]; f = carta[5];
	d1 = mostraCarta(d, false); e1 = mostraCarta(e, false); f1 = mostraCarta(f, false);
	z== d1 ? mostraCarta(d, true):
	z== e1 ? mostraCarta(e, true):
	z== f1 ? mostraCarta(f, true): mulprint(  0, 12);
}
void linha_tela_1_a_10(){
	//linha 1
	printf("%c", 201);  mulprint( 205, 78); printf("%c", 187);
	{//linha 2
	printf("%c", 186);  mulprint(   0, 13); printf("%c %c %c %c", 5, 3, 6, 4);
						mulprint(   0, 13); printf("Kocada Truco");
						mulprint(   0, 13); printf("%c %c %c %c", 5, 3, 6, 4);
						mulprint(   0, 13);	printf("%c", 186);
	}{//linha 3
	printf("%c", 204);  mulprint( 205, 19); printf("%c", 209);
						mulprint( 205, 19); printf("%c", 209);
						mulprint( 205, 19); printf("%c", 209);
						mulprint( 205, 18); printf("%c", 185);
	}{//linha 4
	printf("%c", 186);  mulprint( 0,  9); printf("Players   "); printf("%c", 179);
						mulprint( 0,  9); printf("Pontos    "); printf("%c", 179);
						mulprint( 0, 11);   printf("Jogo    "); printf("%c", 179);
						mulprint( 0,  9); printf("Queda    " ); printf("%c", 186);
	}
	linha_tela_5e_7();
	{//linha 6
	printf("%c", 186);  mulprint( 0, 10); printf("Kocada   ");         printf("%c", 179);
						kocponto==11 ?    printf(" ATENCAO    "):mulprint( 0, 12); 
						printf("%3d    ", kocponto); printf("%c", 179);
						mulprint( 0, 14); printf("%d    ",  kocjogo ); printf("%c", 179);
						mulprint( 0, 11); printf("%3d    ", kocqueda); printf("%c", 186);
	}
	linha_tela_5e_7();
	{//linha 8
	printf("%c", 186);  mulprint( 0,  4); printf("%12s   ", nome);     printf("%c", 179);
						jogponto==11 ?    printf(" ATENCAO    "):mulprint( 0, 12);
						printf("%3d    ", jogponto); printf("%c", 179);
						mulprint( 0, 14); printf("%d    ",  jogjogo ); printf("%c", 179);
						mulprint( 0, 11); printf("%3d    ", jogqueda); printf("%c", 186);
	}{//linha 9
	printf("%c", 204);  mulprint( 205, 19); printf("%c", 216);
						mulprint( 205, 19); printf("%c", 207);
						mulprint( 205, 19); printf("%c", 216);
						mulprint( 205, 18); printf("%c", 185);
	}{//linha 10
	printf("%c", 186);  printf("     Suas cartas   "); printf("%c", 179);
						          mulprint(  177, 39); printf("%c", 179);
						printf ("  Kocada cartas   "); printf("%c", 186);
	}
}
void jogadorJogou(int z){
	int a, b, c, a1, b1, c1;
	a = carta[0]; b = carta[1]; c = carta[2];
	a1 = mostraCarta(a, false); b1 = mostraCarta(b, false); c1 = mostraCarta(c, false);
	z== a1 ? mostraCarta(a, true):
	z== b1 ? mostraCarta(b, true):
	z== c1 ? mostraCarta(c, true): mulprint(  0, 12);
}
void chat_mostraCarta(int w){
	mostraCarta(w, true);
}
void mulprint(int ch, int tam){
	int i;
	for (i=0;i<tam;i++){
		printf("%c", ch);
	}
}
int mostraCarta(int x, bool z){
	char J= 74, Q= 81, K= 75, A= 65;
	int codigo;
	// mostra a carta e passa o codigo de valor
	if(pebar==false){
		x==0 ?  (codigo = 44) &&(z==true ? printf("%2d %c %s",  4, 4, "       "):0):
		x==1 ?  (codigo = 46) &&(z==true ? printf("%2d %c %s",  4, 6, "       "):0):
		x==2 ?  (codigo = 43) &&(z==true ? printf("%2d %c %s",  4, 3, "       "):0):		
		x==3 ?  (codigo = 54) &&(z==true ? printf("%2d %c %s",  5, 4, "       "):0):
		x==4 ?  (codigo = 56) &&(z==true ? printf("%2d %c %s",  5, 6, "       "):0):
		x==5 ?  (codigo = 53) &&(z==true ? printf("%2d %c %s",  5, 3, "       "):0):
		x==6 ?  (codigo = 55) &&(z==true ? printf("%2d %c %s",  5, 5, "       "):0):	
		x==7 ?  (codigo = 64) &&(z==true ? printf("%2d %c %s",  6, 4, "       "):0):
		x==8 ?  (codigo = 66) &&(z==true ? printf("%2d %c %s",  6, 6, "       "):0):
		x==9 ?  (codigo = 63) &&(z==true ? printf("%2d %c %s",  6, 3, "       "):0):
		x==10 ? (codigo = 65) &&(z==true ? printf("%2d %c %s",  6, 5, "       "):0):
		x==11 ? (codigo = 74) &&(z==true ? printf("%2d %c %s",  7, 4, "       "):0):
		x==12 ? (codigo = 76) &&(z==true ? printf("%2d %c %s",  7, 6, "       "):0):
		x==13 ? (codigo = 73) &&(z==true ? printf("%2d %c %s",  7, 3, "       "):0):
		x==14 ? (codigo = 75) &&(z==true ? printf("%2d %c %s",  7, 5, "       "):0):
		x==15 ? (codigo = 84) &&(z==true ? printf("%2d %c %s",  8, 4, "       "):0):
		x==16 ? (codigo = 86) &&(z==true ? printf("%2d %c %s",  8, 6, "       "):0):
		x==17 ? (codigo = 83) &&(z==true ? printf("%2d %c %s",  8, 3, "       "):0):
		x==18 ? (codigo = 85) &&(z==true ? printf("%2d %c %s",  8, 5, "       "):0):
		x==19 ? (codigo = 94) &&(z==true ? printf("%2d %c %s",  9, 4, "       "):0):
		x==20 ? (codigo = 96) &&(z==true ? printf("%2d %c %s",  9, 6, "       "):0):
		x==21 ? (codigo = 93) &&(z==true ? printf("%2d %c %s",  9, 3, "       "):0):
		x==22 ? (codigo = 95) &&(z==true ? printf("%2d %c %s",  9, 5, "       "):0):
		x==23 ? (codigo = 101)&&(z==true ? printf("3%c %c %s", 171,1, " Ferrim"):0):
		x==24 ? (codigo = 111)&&(z==true ? printf("%2d %c %s", 10, 4, "  Ouros"):0):
		x==25 ? (codigo = 121)&&(z==true ? printf("%2d %c %s", 10, 6, "Espadas"):0):
		x==26 ? (codigo = 131)&&(z==true ? printf("%2d %c %s", 10, 3, "  Copas"):0):
		x==27 ? (codigo = 141)&&(z==true ? printf("%2d %c %s", 10, 5, "   Zapp"):0): 0;
		return codigo;
	}else{
		x==0 ?  (codigo = 44) &&(z==true ? printf("%2c %c %s", J, 4, "       "):0):
		x==1 ?  (codigo = 46) &&(z==true ? printf("%2c %c %s", J, 6, "       "):0):
		x==2 ?  (codigo = 43) &&(z==true ? printf("%2c %c %s", J, 3, "       "):0):
		x==3 ?  (codigo = 45) &&(z==true ? printf("%2c %c %s", J, 5, "       "):0):		
		x==4 ?  (codigo = 54) &&(z==true ? printf("%2c %c %s", Q, 4, "       "):0):
		x==5 ?  (codigo = 56) &&(z==true ? printf("%2c %c %s", Q, 6, "       "):0):
		x==6 ?  (codigo = 53) &&(z==true ? printf("%2c %c %s", Q, 3, "       "):0):
		x==7 ?  (codigo = 55) &&(z==true ? printf("%2c %c %s", Q, 5, "       "):0):	
		x==8 ?  (codigo = 64) &&(z==true ? printf("%2c %c %s", K, 4, "       "):0):
		x==9 ?  (codigo = 66) &&(z==true ? printf("%2c %c %s", K, 6, "       "):0):
		x==10 ? (codigo = 63) &&(z==true ? printf("%2c %c %s", K, 3, "       "):0):
		x==11 ? (codigo = 65) &&(z==true ? printf("%2c %c %s", K, 5, "       "):0):
		x==12 ? (codigo = 74) &&(z==true ? printf("%2c %c %s", A, 4, "       "):0):
		x==13 ? (codigo = 73) &&(z==true ? printf("%2c %c %s", A, 3, "       "):0):
		x==14 ? (codigo = 75) &&(z==true ? printf("%2c %c %s", A, 5, "       "):0):
		x==15 ? (codigo = 84) &&(z==true ? printf("%2d %c %s", 2, 4, "       "):0):
		x==16 ? (codigo = 86) &&(z==true ? printf("%2d %c %s", 2, 6, "       "):0):
		x==17 ? (codigo = 83) &&(z==true ? printf("%2d %c %s", 2, 3, "       "):0):
		x==18 ? (codigo = 85) &&(z==true ? printf("%2d %c %s", 2, 5, "       "):0):
		x==19 ? (codigo = 94) &&(z==true ? printf("%2d %c %s", 3, 4, "       "):0):
		x==20 ? (codigo = 96) &&(z==true ? printf("%2d %c %s", 3, 6, "       "):0):
		x==21 ? (codigo = 93) &&(z==true ? printf("%2d %c %s", 3, 3, "       "):0):
		x==22 ? (codigo = 95) &&(z==true ? printf("%2d %c %s", 3, 5, "       "):0):
		x==23 ? (codigo = 101)&&(z==true ? printf("3%c %c %s", 171,1," Ferrim"):0):
		x==24 ? (codigo = 111)&&(z==true ? printf("%2d %c %s", 7, 4, "  Ouros"):0):
		x==25 ? (codigo = 121)&&(z==true ? printf("%2c %c %s", A, 6, "Espadas"):0):
		x==26 ? (codigo = 131)&&(z==true ? printf("%2d %c %s", 7, 3, "  Copas"):0):
		x==27 ? (codigo = 141)&&(z==true ? printf("%2d %c %s", 4, 5, "   Zapp"):0): 0;
		return codigo;
	}
}
void mostraTurno(int turno, int z){
	if(z==0){
		mulprint(  0, 15);
		printf(" Turno %d ", turno);
		mulprint(  0, 15);
	}else if(turno==3 && z==1){ 
		mulprint(  0, 13);
		printf("%c%c Turno %d ", 1, 1, turno);
		mulprint(  0, 15);
	}else if(turno==3 && z==2){ 
		mulprint(  0, 15);
		printf(" Turno %d %c%c", turno, 2, 2);
		mulprint(  0, 13);
	}else if(z==1){ 
		mulprint(  0, 14);
		printf("%c Turno %d ", 1, turno);
		mulprint(  0, 15);
	}else if(z==2){ 
		mulprint(  0, 15);
		printf(" Turno %d %c", turno, 2);
		mulprint(  0, 14);
	}
}
char escolhe( int x, bool z, bool ja, bool jb, bool jc, bool truc){
	int i=1;
	char ch;
	while(i==1){
		printf( " Escolha: ");
		if(truc==true){ 
			printf(" %c1. Aceitar\t", 175);
			printf("    %c2. Aceitar\t\t", 175);
			printf("     %c3. Aceitar\t", 175);
		}else{
			printf(" %c1. ", 175);     ja==false ? mostraCarta(carta[0], true) : jogJogou();
			printf(" %c2. ", 175);     jb==false ? mostraCarta(carta[1], true) : jogJogou();
			printf("     %c3. ", 175); jc==false ? mostraCarta(carta[2], true) : jogJogou();
		}
		printf("\n\t   %c4. Correr \t   ", 175);
		x==1? (z==true ? printf( " %c5. Trucar\t    ", 175): printf("\t\t")):		
		x==3? (z==true ? printf( " %c5. Pedir Seis\t", 175): printf("\t\t")):
		x==6? (z==true ? printf( " %c5. Pedir Nove\t", 175): printf("\t\t")):
		x==9? (z==true ? printf( " %c5. Pedir Doze\t", 175): printf("\t\t")):0;
		printf("     %cEscolheu: ", 175);
		scanf("%c%c", &ch, &lixo);
				 if(ch<='0' || ch>='6')    { printf(" ! Numero invalido\n\n"); i=1;	}
			else if(truc==true) i=0;	 
			else if(ch=='1'&& ja==true) { printf(" !!! Ja jogou esta carta teimoso\n\n"); i=1;	}
			else if(ch=='2'&& jb==true) { printf(" !!! Ja jogou esta carta teimoso\n\n"); i=1;	} 
			else if(ch=='3'&& jc==true) { printf(" !!! Ja jogou esta carta teimoso\n\n"); i=1;	}
			else if(ch=='5'&& z==false) { printf(" ! Recurso indisponivel\n\n");          i=1;	}
			else i=0;
	}
	return ch;		
}
