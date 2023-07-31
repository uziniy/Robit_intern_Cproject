//
//  main.c
//  Robit_project_C
//
//  Created by 최우진 on 2023/07/30.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
struct game_setting{//구조체
    char **p_role;
    char **L_role;
};


int f_avalon(char **p_role,char **L_role,FILE * fp);
int f_mapia(char **p_role,char **L_role,FILE * fp2);
int f_liar(char **p_role,char **L_role,FILE * fp3);
int f_baboliar(char **p_role,char **L_role,FILE * fp4);
int f_spyliar(char **p_role,char **L_role,FILE * fp5);


int main(int argc, const char * argv[]) {
    int gc;//game chose
    printf("진행하실 게임을 선택하세요.\n");
    printf("1.아발론\n2.마피아\n3.라이어\n4.바보라이어\n5.스파이라이어\n:");
    scanf("%d",&gc);
    srand((unsigned int)time(NULL));
    if(gc==1){
        FILE * fp = fopen("아발론_직업_확인.txt", "w");//파일 만들기
        fprintf(fp, "아발론 직업 확인창");
        fclose(fp);
        struct game_setting *avalon = malloc(sizeof(struct game_setting));//구조체 동적할당
        avalon->p_role = (char **)malloc(sizeof(char *) * 100);//구조체 포인터 활용
        for (int i = 0; i < 100; i++) {
            avalon->p_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        avalon->L_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            avalon->L_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        f_avalon(avalon->p_role, avalon->L_role, fp);
        
    }
    else if(gc==2){
        FILE * fp2 = fopen("마피아_직업_확인.txt", "w");//파일 만들기
        fprintf(fp2, "마피아 직업 확인창");
        fclose(fp2);
        struct game_setting *mapia = malloc(sizeof(struct game_setting));
        mapia->p_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            mapia->p_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        mapia->L_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            mapia->L_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        f_mapia(mapia->p_role, mapia->L_role, fp2);
    }
    else if(gc==3){
        FILE * fp3 = fopen("라이어_제시어_확인.txt", "w");//파일 만들기
        fprintf(fp3, "라이어게임 제시어 확인창");
        fclose(fp3);
        struct game_setting *liar = malloc(sizeof(struct game_setting));
        liar->p_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            liar->p_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        liar->L_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            liar->L_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        f_liar(liar->p_role, liar->L_role, fp3);
    }
    else if(gc==4){
        FILE * fp4 = fopen("바보_라이어_제시어_확인.txt", "w");//파일 만들기
        fprintf(fp4, "바보_라이어게임 제시어 확인창");
        fclose(fp4);
        struct game_setting *baboliar = malloc(sizeof(struct game_setting));
        baboliar->p_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            baboliar->p_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        baboliar->L_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            baboliar->L_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        f_baboliar(baboliar->p_role, baboliar->L_role, fp4);
    }
    else if(gc==5){
        FILE * fp5 = fopen("스파이_라이어_제시어_확인.txt", "w");//파일 만들기
        fprintf(fp5, "스파이_라이어게임 제시어 확인창");
        fclose(fp5);
        struct game_setting *spyliar = malloc(sizeof(struct game_setting));
        spyliar->p_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            spyliar->p_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        spyliar->L_role = (char **)malloc(sizeof(char *) * 100);
        for (int i = 0; i < 100; i++) {
            spyliar->L_role[i] = (char *)malloc(sizeof(char) * 100);
        }
        f_spyliar(spyliar->p_role, spyliar->L_role, fp5);
    }
    return 0;
}

int f_avalon(char **p_role,char **L_role,FILE * fp){
    //seed rand
    srand((unsigned int)time(NULL));
    int num,i,p_sum,n;
    
    //게임 시작하고 나오는 멘트
    printf("아발론을 선택하셨습니다.\n");
    printf("인원을 선택해주세요(5~10명 숫자로 입력) : ");
    scanf("%d",&p_sum);
    
    switch (p_sum) {
        case 5:
            strcpy(p_role[0], "신하(선팀)");
            strcpy(p_role[1], "퍼시벌(선팀)");
            strcpy(p_role[2], "멀린(선팀)");
            strcpy(p_role[3], "모르가나(악팀)");
            strcpy(p_role[4], "암살자(악팀)");
            for (i=0; i<5; i++) {
                num = rand() % (5-i);
                L_role[i]=p_role[num];
                //remove
                for (int j=0; j<5-i; j++) {
                    if(strcmp(L_role[i], p_role[j])==0){
                        for (int k=j; k<5-i; k++) {
                            p_role[k]=p_role[k+1];
                        }
                    }
                }
            }
            for (int j=0; j<5; j++) {
                fp = fopen("아발론_직업_확인.txt", "w+");
                fprintf(fp,"%d번님 당신의 직업은 %s입니다.\n",j+1,L_role[j]);
                printf("%d번님 아발론_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }
            }
            break;
        case 6:
            strcpy(p_role[0], "신하(선팀)");
            strcpy(p_role[1], "퍼시벌(선팀)");
            strcpy(p_role[2], "멀린(선팀)");
            strcpy(p_role[3], "모르가나(악팀)");
            strcpy(p_role[4], "암살자(악팀)");
            strcpy(p_role[5], "신하2(선팀)");
            
            for (i=0; i<6; i++) {
                num = rand() % (6-i);
                L_role[i]=p_role[num];
                //remove
                for (int j=0; j<6-i; j++) {
                    if(strcmp(L_role[i], p_role[j])==0){
                        for (int k=j; k<6-i; k++) {
                            p_role[k]=p_role[k+1];
                        }
                    }
                }
            }
            for (int j=0; j<6; j++) {
                fp = fopen("아발론_직업_확인.txt", "w+");
                fprintf(fp,"%d번님 당신의 직업은 %s입니다.\n",j+1,L_role[j]);
                printf("%d번님 아발론_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }
            }
            
            break;
        case 7:
            strcpy(p_role[0], "신하(선팀)");
            strcpy(p_role[1], "퍼시벌(선팀)");
            strcpy(p_role[2], "멀린(선팀)");
            strcpy(p_role[3], "모르가나(악팀)");
            strcpy(p_role[4], "모드레드(악팀)");
            strcpy(p_role[5], "신하2(선팀)");
            strcpy(p_role[6], "암살자(악팀)");
            
            for (i=0; i<7; i++) {
                num = rand() % (7-i);
                L_role[i]=p_role[num];
                //remove
                for (int j=0; j<7-i; j++) {
                    if(strcmp(L_role[i], p_role[j])==0){
                        for (int k=j; k<7-i; k++) {
                            p_role[k]=p_role[k+1];
                        }
                    }
                }
            }
            for (int j=0; j<7; j++) {
                fp = fopen("아발론_직업_확인.txt", "w+");
                fprintf(fp,"%d번님 당신의 직업은 %s입니다.\n",j+1,L_role[j]);
                printf("%d번님 아발론_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }

            }
            
            break;
        case 8:
            strcpy(p_role[0], "신하(선팀)");
            strcpy(p_role[1], "퍼시벌(선팀)");
            strcpy(p_role[2], "멀린(선팀)");
            strcpy(p_role[3], "모르가나(악팀)");
            strcpy(p_role[4], "모드레드(악팀)");
            strcpy(p_role[5], "신하2(선팀)");
            strcpy(p_role[6], "암살자(악팀)");
            strcpy(p_role[7], "신하3(선팀)");
            
            for (i=0; i<8; i++) {
                num = rand() % (8-i);
                L_role[i]=p_role[num];
                //remove
                for (int j=0; j<8-i; j++) {
                    if(strcmp(L_role[i], p_role[j])==0){
                        for (int k=j; k<8-i; k++) {
                            p_role[k]=p_role[k+1];
                        }
                    }
                }
            }
            for (int j=0; j<8; j++) {
                fp = fopen("아발론_직업_확인.txt", "w+");
                fprintf(fp,"%d번님 당신의 직업은 %s입니다.\n",j+1,L_role[j]);
                printf("%d번님 아발론_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }

            }
            
            break;
        case 9:
            strcpy(p_role[0], "신하(선팀)");
            strcpy(p_role[1], "퍼시벌(선팀)");
            strcpy(p_role[2], "멀린(선팀)");
            strcpy(p_role[3], "모르가나(악팀)");
            strcpy(p_role[4], "모드레드(악팀)");
            strcpy(p_role[5], "신하(선팀)");
            strcpy(p_role[6], "암살자(악팀)");
            strcpy(p_role[7], "신하3(선팀)");
            strcpy(p_role[8], "신하4(선팀)");
            for (int i=0; i<9; i++) {
                num = rand() % (9-i);
                L_role[i]=p_role[num];
                //remove
                for (int j=0; j<9-i; j++) {
                    if(strcmp(L_role[i], p_role[j])==0){
                        for (int k=j; k<9-i; k++) {
                            p_role[k]=p_role[k+1];
                        }
                    }
                }
            }
            for (int j=0; j<9; j++) {
                fp = fopen("아발론_직업_확인.txt", "w+");
                fprintf(fp,"%d번님 당신의 직업은 %s입니다.\n",j+1,L_role[j]);
                printf("%d번님 아발론_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }

            }
            
            break;
        case 10:
            strcpy(p_role[0], "신하(선팀)");
            strcpy(p_role[1], "퍼시벌(선팀)");
            strcpy(p_role[2], "멀린(선팀)");
            strcpy(p_role[3], "모르가나(악팀)");
            strcpy(p_role[4], "모드레드(악팀)");
            strcpy(p_role[5], "신하2(선팀)");
            strcpy(p_role[6], "암살자(악팀)");
            strcpy(p_role[7], "악의 신하(악팀)");
            strcpy(p_role[8], "신하3(선팀)");
            strcpy(p_role[9], "신하4(선팀)");
            for (i=0; i<10; i++) {
                num = rand() % (10-i);
                L_role[i]=p_role[num];
                //remove
                for (int j=0; j<10-i; j++) {
                    if(strcmp(L_role[i], p_role[j])==0){
                        for (int k=j; k<10-i; k++) {
                            p_role[k]=p_role[k+1];
                        }
                    }
                }
            }
            for (int j=0; j<10; j++) {
                fp = fopen("아발론_직업_확인.txt", "w+");
                fprintf(fp,"%d번님 당신의 직업은 %s입니다.\n",j+1,L_role[j]);
                printf("%d번님 아발론_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }

            }
            
            break;
            
        default:
            break;
    }
    
    printf("역할 배정이 끝났습니다. 게임을 시작해주세요!\n");
    printf("개개인의 역할 정보는 아발론_직업_확인.txt에 저장해두었습니다.\n\n<끝나고 확인하세요!>\n");
    fp = fopen("아발론_직업_확인.txt", "w+");
    for (int j=0; j<p_sum; j++) {
        fprintf(fp,"%4d번 : %s\n",j+1,L_role[j]);
    }
    fclose(fp);
    free(p_role);
    free(L_role);
    
    return 0;
}
int f_mapia(char **p_role,char **L_role,FILE * fp2){
    int p_sum,i,num,n;
    srand((unsigned int)time(NULL));

    //게임 시작하고 나오는 멘트
    printf("마피아게임을 선택하셨습니다.\n");
    printf("인원을 선택해주세요(8~10명 숫자로 입력) : ");
    scanf("%d",&p_sum);
    printf("%d명 선택하셨습니다.\n",p_sum);
    
    switch (p_sum) {
        case 8:
            strcpy(L_role[0], "마피아1");
            strcpy(L_role[1], "마피아2");
            strcpy(L_role[2], "경찰");
            strcpy(L_role[3], "의사");
            strcpy(L_role[4], "시민1");
            strcpy(L_role[5], "시민2");
            strcpy(L_role[6], "시민3");
            strcpy(L_role[7], "시민4");

            for (i=0; i<8; i++) {
                num = rand() % (8-i);
                strcpy(p_role[i], L_role[num]);
                for (int j=0; j<8-i; j++) {
                    if(strcmp(L_role[num], L_role[j])==0){
                        for (int k=j; k<8; k++) {
                            strcpy(L_role[k],L_role[k+1]);
                        }
                    }
                }
            }
            for (int j=0; j<8; j++) {
                fp2 = fopen("마피아_직업_확인.txt", "w+");
                fprintf(fp2,"%d번님 당신의 직업은 %s입니다.\n",j+1,p_role[j]);
                printf("%d번님 마피아_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp2);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }
            }
            break;
            
        case 9:
            strcpy(L_role[0], "마피아1");
            strcpy(L_role[1], "마피아2");
            strcpy(L_role[2], "경찰");
            strcpy(L_role[3], "의사");
            strcpy(L_role[4], "시민1");
            strcpy(L_role[5], "시민2");
            strcpy(L_role[6], "시민3");
            strcpy(L_role[7], "시민4");
            strcpy(L_role[8], "시민5");

            for (i=0; i<9; i++) {
                num = rand() % (9-i);//랜덤돌려
                strcpy(p_role[i], L_role[num]);//그걸 0번부터 갖다 넣어
                for (int j=0; j<9-i; j++){
                    if(strcmp(L_role[num], L_role[j])==0){
                        for (int k=j; k<9; k++) {
                            strcpy(L_role[k],L_role[k+1]);
                        }
                    }
                }
            }
            for (int j=0; j<9; j++) {
                fp2 = fopen("마피아_직업_확인.txt", "w+");
                fprintf(fp2,"%d번님 당신의 직업은 %s입니다.\n",j+1,p_role[j]);
                printf("%d번님 마피아_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp2);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }
            }
            break;
            
        case 10:
            strcpy(L_role[0], "마피아1");
            strcpy(L_role[1], "마피아2");
            strcpy(L_role[2], "경찰");
            strcpy(L_role[3], "의사");
            strcpy(L_role[4], "시민1");
            strcpy(L_role[5], "시민2");
            strcpy(L_role[6], "시민3");
            strcpy(L_role[7], "시민4");
            strcpy(L_role[8], "시민5");
            strcpy(L_role[9], "마피아3");

            for (i=0; i<10; i++) {
                num = rand() % (10-i);
                strcpy(p_role[i], L_role[num]);
                for (int j=0; j<10-i; j++) {
                    if(strcmp(L_role[num], L_role[j])==0){
                        for (int k=j; k<10; k++) {
                            strcpy(L_role[k],L_role[k+1]);
                        }
                    }
                }
            }
            for (int j=0; j<10; j++) {
                fp2 = fopen("마피아_직업_확인.txt", "w+");
                fprintf(fp2,"%d번님 당신의 직업은 %s입니다.\n",j+1,p_role[j]);
                printf("%d번님 마피아_직업_확인.txt파일로 이동해서 직업을 확인해주세요.\n",j+1);
                printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
                fclose(fp2);
                scanf("%d",&n);
                printf("\n\n");
                if(n!=1){
                    printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
                    return 0;
                }
            }
            break;
            
        default:
            break;
    }
    printf("역할 배정이 끝났습니다. 게임을 시작해주세요!\n");
    printf("개개인의 역할 정보는 마피아_직업_확인.txt에 저장해두었습니다.\n 끝나고 확인하세요!\n");
    fp2 = fopen("마피아_직업_확인.txt", "w+");
    for (int j=0; j<p_sum; j++) {
        fprintf(fp2,"%4d번 : %s\n",j+1,L_role[j]);
    }
    fclose(fp2);
    free(p_role);//메모리 해제
    free(L_role);
    return 0;
    
    
}
int f_liar(char **p_role,char **L_role,FILE * fp3){
    int p_sum,i,num,num2,n;
    srand((unsigned int)time(NULL));
    num = rand() % 5;
    strcpy(L_role[0], "딸기");
    strcpy(L_role[1], "당근");
    strcpy(L_role[2], "수박");
    strcpy(L_role[3], "참외");
    strcpy(L_role[4], "메론");
    
    //게임 시작하고 나오는 멘트
    printf("라이어게임을 선택하셨습니다.\n");
    printf("인원을 선택해주세요(2명 이상 숫자로 입력) : ");
    scanf("%d",&p_sum);
    if(p_sum<2){
        printf("게임 진행 인원수가 부족합니다.\n");
        return 0;
    }
    printf("%d명 선택하셨습니다.\n",p_sum);
    
    for (i=0; i<p_sum; i++) {
        strcpy(p_role[i], L_role[num]);
    }
    num2 = rand() % p_sum;
    strcpy(p_role[num2], "라이어");
    
    for (int j=0; j<p_sum; j++) {
        fp3 = fopen("라이어_제시어_확인.txt", "w+");
        fprintf(fp3,"%d번 plater : %s\n",j+1,p_role[j]);
        printf("%d번님 라이어_제시어_확인.txt파일로 이동해서 제시어를 확인해주세요.\n",j+1);
        printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
        fclose(fp3);
        scanf("%d",&n);
        printf("\n\n");
        if(n!=1){
            printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
            return 0;
        }
    }
    printf("역할 배정이 끝났습니다. 게임을 시작해주세요!\n");
    printf("라이어가 누군지는 라이어_제시어_확인.txt파일에 저장해두었습니다!\n 끝나고 확인하세요!\n");
    fp3 = fopen("라이어_제시어_확인.txt", "w+");
    fprintf(fp3,"%4d번 : %s\n",num2+1,p_role[num2]);
    fclose(fp3);
    free(p_role);//메모리 해제
    free(L_role);
    return 0;
}

int f_baboliar(char **p_role,char **L_role,FILE * fp4){
    int p_sum,i,num,num2,n;
    srand((unsigned int)time(NULL));
    num = rand() % 5;
    strcpy(L_role[0], "딸기");
    strcpy(L_role[1], "당근");
    strcpy(L_role[2], "수박");
    strcpy(L_role[3], "참외");
    strcpy(L_role[4], "메론");
    
    //게임 시작하고 나오는 멘트
    printf("바보라이어게임을 선택하셨습니다.\n");
    printf("인원을 선택해주세요(2명 이상 숫자로 입력) : ");
    scanf("%d",&p_sum);
    if(p_sum<2){
        printf("게임 진행 인원수가 부족합니다.\n");
        return 0;
    }
    printf("%d명 선택하셨습니다.\n",p_sum);

    for (i=0; i<p_sum; i++) {
        strcpy(p_role[i], L_role[num]);
    }
    num2 = rand() % p_sum;
    num = rand() % 5;
    strcpy(p_role[num2], L_role[num]);
    
    for (int j=0; j<p_sum; j++) {
        fp4 = fopen("바보_라이어_제시어_확인.txt", "w+");
        fprintf(fp4,"%d번 plater : %s\n",j+1,p_role[j]);
        printf("%d번님 바보_라이어_제시어_확인.txt파일로 이동해서 제시어를 확인해주세요.\n",j+1);
        printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
        fclose(fp4);
        scanf("%d",&n);
        printf("\n\n");
        if(n!=1){
            printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
            return 0;
        }
    }
    printf("역할 배정이 끝났습니다. 게임을 시작해주세요!\n");
    printf("바보 라이어가 누군지는 바보_라이어_제시어_확인.txt파일에 저장해두었습니다!\n 끝나고 확인하세요!\n");
    fp4 = fopen("바보_라이어_제시어_확인.txt", "w+");
    fprintf(fp4,"%4d번 : %s\n",num2+1,p_role[num2]);
    fclose(fp4);
    free(p_role);//메모리 해제
    free(L_role);

    
    return 0;
}

int f_spyliar(char **p_role,char **L_role,FILE * fp5){
    int p_sum,i,num,num2,n;
    srand((unsigned int)time(NULL));
    
    //라이어 제시어 넣는 곳
    num = rand() % 5;
    strcpy(L_role[0], "딸기");
    strcpy(L_role[1], "당근");
    strcpy(L_role[2], "수박");
    strcpy(L_role[3], "참외");
    strcpy(L_role[4], "메론");
    
    //게임 시작하고 나오는 멘트
    printf("스파이라이어게임을 선택하셨습니다.\n");
    printf("인원을 선택해주세요(3명 이상 숫자로 입력) : ");
    scanf("%d",&p_sum);
    if(p_sum<3){
        printf("게임 진행 인원수가 부족합니다.\n");
        return 0;
    }
    printf("%d명 선택하셨습니다.\n",p_sum);
    
    //기본 세팅
    for (i=0; i<p_sum; i++) {
        strcpy(p_role[i], L_role[num]);
    }
    
    num2 = rand() % p_sum;
    strcpy(p_role[num2], "라이어");
    for (int j=0; j<p_sum; j++) {
        int num3 = rand() % p_sum-1;
        if(num3!=num2){
            strcat(p_role[num3], "_스파이");
            break;
        }
    }
    for (int j=0; j<p_sum; j++) {
        fp5 = fopen("스파이_라이어_제시어_확인.txt", "w+");
        fprintf(fp5,"%d번 plater : %s\n",j+1,p_role[j]);
        printf("%d번님 스파이_라이어_제시어_확인.txt파일로 이동해서 제시어를 확인해주세요.\n",j+1);
        printf("확인이 완료 되었다면 파일을 닫고 1을 입력해주세요.");
        fclose(fp5);
        scanf("%d",&n);
        printf("\n\n");
        if(n!=1){
            printf("문제가 발생했습니다. 프로그램을 종료합니다.\n");
            return 0;
        }
        printf("\n\n");
    }
    printf("역할 배정이 끝났습니다. 게임을 시작해주세요!\n");
    printf("바보 라이어가 누군지는 스파이_라이어_제시어_확인.txt파일에 저장해두었습니다!\n 끝나고 확인하세요!\n");
    fp5 = fopen("스파이_라이어_제시어_확인.txt", "w+");
    fprintf(fp5,"%4d번 : %s\n",num2+1,p_role[num2]);
    fclose(fp5);
    free(p_role);//메모리 해제
    free(L_role);
    return 0;
}
