#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//BATALHA NAVAL

int main()
{
    int l, c, cont=0, tentativas=0;
    char m1[10][10], m2[10][10];
    srand(time(NULL));
    
    for(l=0;l<10; l++){
        for(c=0;c<10;c++){
            m1[l][c] = '-';
            m2[l][c] = '-';
        }
    }
    for(int i=0;i<5; i++){
        l = rand()%10;
        c = rand()%10;
        while(m1[l][c] == 'S'){
            l = rand()%10;
            c = rand()%10;
        }
        m1[l][c]= 'S';
    }
    printf("  0 1 2 3 4 5 6 7 8 9\n");
    for(l=0;l<10; l++){
        printf("%d", l);
        for(c=0;c<10;c++){
            printf(" %c", m2[l][c]);
        }
        printf("\n");
    }
    
    while(tentativas < 10){
        printf("\nDigite a linha para atirar: ");
        scanf("%d", &l);
        printf("\nDigite a coluna para atirar: ");
        scanf("%d", &c);

        if(l>9 || l<0 || c>9 || c<0){
            printf("\nPosicao inexistente!\n");
            continue;
        }
        if (m1[l][c] == '-'){
            printf("\nAgua!\n");
            m2[l][c] = 'A';   
            
            tentativas++;
        }
        else{
            printf("\nSubmarino!!!\n");
            m2[l][c] = 'S';
            cont++;
        }
        printf("  0 1 2 3 4 5 6 7 8 9\n");
        for(l=0;l<10; l++){
            printf("%d", l);
            for(c=0;c<10;c++){
                printf(" %c", m2[l][c]);
            }
            printf("\n");
        }

        if(cont==5) break;
        
    }
    
    if(cont==5){
        printf("\n\n\tYOU WIN!!!\n\n\n");
    }
    else printf("\nAs suas tentativas acabaram...\n\n\tGame Over!\n\n\n");
    
    return 0;
}