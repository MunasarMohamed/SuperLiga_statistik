#include <stdio.h>
#include <string.h>

typedef struct
{
    char holdnavn[4];
    int point;
    int antal_mah;
    int antal_mmh;
} hold;

enum uge {man,tir,ons,tor,fre,lor,son};

typedef struct
{
    enum uge dag;
    int dato;
    int tid;
    char hjemme[3];
    char ude[3];
    int point_hjemme;
    int point_ude;
    int tilskuer;

} kamp;

int find_team_index(hold superligaen[], int size, char team[])
{
    for (int i = 0; i < size; i++)
    {
        if(strcmp(superligaen[i].holdnavn, team) == 0)
        {
            return i;
        }
    }
        return -1;
}

int main(void) {
    char day[4];
    int dato;
    int måned;
    int timer;
    int minutter;
    char hold1[4];
    char hold2[4];
    int point1 = 0;
    int point2 = 0;
    int tilskuer;

    FILE * file;

    file = fopen("C:/Users/munas/OneDrive/Skrivebord/Personal Projects/Superliga statistik/kampe-2024-2025.txt","r");

hold superligaen[] =  {
{"AGF",0,0, 0},
{"FCK",0,0, 0},
{"FCM",0,0, 0},
{"SIF",0,0, 0},
{"RFC",0,0, 0},
{"BIF",0,0, 0},
{"FCN",0,0, 0},
{"VFF",0,0, 0},
{"AaB",0,0, 0},
{"SJF",0,0, 0},
{"LBK",0,0, 0},
{"VB",0,0, 0}
};
int num_teams = sizeof(superligaen)/sizeof(superligaen[0]);

if(file)
{
    while(fscanf(file,"%s %d/%d %d.%d %s - %s %d - %d %d", &day, &dato, &måned, &timer, &minutter, hold1, hold2, &point1, &point2, &tilskuer) != EOF)
    {
        int home_index = find_team_index(superligaen, num_teams, hold1);
        int away_index = find_team_index(superligaen, num_teams, hold2);

        if (home_index != -1 && away_index != -1)
        {
            superligaen[home_index].antal_mah += point1;
            superligaen[home_index].antal_mmh += point2;
            superligaen[home_index].point += (point1 > point2) ? 3 : (point1 == point2 ? 1 : 0);

            superligaen[away_index].antal_mah += point2;
            superligaen[away_index].antal_mmh += point1;
            superligaen[away_index].point += (point2 > point1) ? 3 : (point1 == point2 ? 1 : 0);;
        } else
        {
            printf("Error!");
        }
    }
}

    fclose(file);

for (int i = 0; i < 12; i++)
{
    printf("Klub %-2d - %-3s   Point: %-3d   M-a-h: %-3d   M-m-h: %-3d\n", i+1, superligaen[i].holdnavn, superligaen[i].point, superligaen[i].antal_mah, superligaen[i].antal_mmh);
}

    return 0;
}
