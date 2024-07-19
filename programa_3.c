#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>
#include <locale.h>

#define MAX_LINE_LENGTH 10000
#define MAX_FILENAME_LENGTH 100
#define VECTORS 7

char Te_recom[MAX_LINE_LENGTH], Te_fort[MAX_LINE_LENGTH], te_op[MAX_LINE_LENGTH];
int control;
int vec[VECTORS];

void Strings(float cal);
void vector(int max);

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void vector(int max)
{
    srand(time(NULL) ^ pthread_self());
    int count = 0;
    int *used = (int *)calloc(max + 1, sizeof(int)); // Allocate and initialize used array

    if (used == NULL)
    {
        perror("Error allocating memory for used array");
        exit(EXIT_FAILURE);
    }

    while (count < VECTORS)
    {
        int val = rand() % max + 1;
        if (!used[val])
        {
            vec[count++] = val;
            used[val] = 1;
        }
    }

    free(used); // Free allocated memory
    control = 1;
}

void Strings(float cal)
{
    char Aux_1[1000];
    char numero[2];
    if (cal <= 6)
    {
        vector(14);
        for (int i = 0; i < VECTORS; i++)
        {
            char NameText[35] = "resources\\Op_5-6_";
            sprintf(numero, "%d", vec[i]);
            strcat(NameText, numero);
            strcat(NameText, ".txt");
            FILE *Texts = fopen(NameText, "r");
            fgets(Aux_1, sizeof(Aux_1), Texts);
            fclose(Texts);
            if (control == 1)
            {
                strcpy(te_op, Aux_1);
                control = 0;
            }
            else
            {
                strcat(te_op, Aux_1);
            }
        }

        vector(14);
        for (int i = 0; i < VECTORS; i++)
        {
            char NameText[35] = "resources\\Fort_5-6_";
            sprintf(numero, "%d", vec[i]);
            strcat(NameText, numero);
            strcat(NameText, ".txt");
            FILE *Texts = fopen(NameText, "r");
            fgets(Aux_1, sizeof(Aux_1), Texts);
            fclose(Texts);
            if (control == 1)
            {
                strcpy(Te_fort, Aux_1);
                control = 0;
            }
            else
            {
                strcat(Te_fort, Aux_1);
            }
        }
    }
    else if (cal <= 8)
    {
        vector(14);
        for (int i = 0; i < VECTORS; i++)
        {
            char NameText[35] = "resources\\Op_7-8_";
            sprintf(numero, "%d", vec[i]);
            strcat(NameText, numero);
            strcat(NameText, ".txt");
            FILE *Texts = fopen(NameText, "r");
            fgets(Aux_1, sizeof(Aux_1), Texts);
            fclose(Texts);
            if (control == 1)
            {
                strcpy(te_op, Aux_1);
                control = 0;
            }
            else
            {
                strcat(te_op, Aux_1);
            }
        }

        vector(14);
        for (int i = 0; i < VECTORS; i++)
        {
            char NameText[35] = "resources\\Fort_7-8_";
            sprintf(numero, "%d", vec[i]);
            strcat(NameText, numero);
            strcat(NameText, ".txt");
            FILE *Texts = fopen(NameText, "r");
            fgets(Aux_1, sizeof(Aux_1), Texts);
            fclose(Texts);
            if (control == 1)
            {
                strcpy(Te_fort, Aux_1);
                control = 0;
            }
            else
            {
                strcat(Te_fort, Aux_1);
            }
        }
    }
    else
    {
        vector(14);
        for (int i = 0; i < VECTORS; i++)
        {

            char NameText[35] = "resources\\Op_7-8_";
            // printf("File 2: %s\t->",NameText);
            sprintf(numero, "%d", vec[i]);
            strcat(NameText, numero);
            // printf("%s\t->",NameText);
            strcat(NameText, ".txt");
            // printf("%s\n",NameText);

            FILE *Texts = fopen(NameText, "r");
            fgets(Aux_1, sizeof(Aux_1), Texts);
            fclose(Texts);
            if (control == 1)
            {
                strcpy(te_op, Aux_1);
                control = 0;
            }
            else
            {
                strcat(te_op, Aux_1);
            }
        }
        // printf("String Op: %s\n",te_op);

        vector(14);
        for (int i = 0; i < VECTORS; i++)
        {
            char NameText[35] = "resources\\Fort_9-10_";
            sprintf(numero, "%d", vec[i]);
            strcat(NameText, numero);
            strcat(NameText, ".txt");
            FILE *Texts = fopen(NameText, "r");
            fgets(Aux_1, sizeof(Aux_1), Texts);
            fclose(Texts);
            if (control == 1)
            {
                strcpy(Te_fort, Aux_1);
                control = 0;
            }
            else
            {
                strcat(Te_fort, Aux_1);
            }
        }
    }

    vector(14);
    for (int i = 0; i < 5; i++)
    {
        char NameText[35] = "resources\\Recom_";
        sprintf(numero, "%d", vec[i]);
        strcat(NameText, numero);
        strcat(NameText, ".txt");
        FILE *Texts = fopen(NameText, "r");
        fgets(Aux_1, sizeof(Aux_1), Texts);
        fclose(Texts);
        if (control == 1)
        {
            strcpy(Te_recom, Aux_1);
            control = 0;
        }
        else
        {
            strcat(Te_recom, Aux_1);
        }
    }
}

void *func(void *arg)
{
    char *st = (char *)arg;
    char *token;
    char *Grade, *Grupe, *Cicle, *ZonData, *SecData, *Escuela, *Nombre, *Calificacion;
    float calificacion_float;
    char fname[MAX_FILENAME_LENGTH];
    FILE *Out;

    token = strtok(st, ",");
    ZonData = token;
    token = strtok(NULL, ",");
    SecData = token;
    token = strtok(NULL, ",");
    Escuela = token;
    token = strtok(NULL, ",");
    Grade = token;
    token = strtok(NULL, ",");
    Grupe = token;
    token = strtok(NULL, ",");
    Cicle = token;
    token = strtok(NULL, ",");
    Nombre = token;
    token = strtok(NULL, ",");
    Calificacion = token;

    calificacion_float = atof(Calificacion);
    if (calificacion_float == 0.0 && Calificacion[0] != '0')
    {
        printf("Error: No se pudo convertir la calificación '%s' a float.\n", Calificacion);
        return NULL;
    }

    Strings(calificacion_float);
    sprintf(fname, "%s-%s-%s.tex", Nombre, Grade, Grupe);
    for (int i = 0; fname[i]; i++)
    {
        if (fname[i] == ' ')
            fname[i] = '-';
    }

    Out = fopen(fname, "w");
    if (Out == NULL)
    {
        printf("Error opening file for writing: %s\n", fname);
        return NULL;
    }

    fprintf(Out, "\\documentclass{memoir}\n");
    fprintf(Out, "\\usepackage[final]{graphicx}\n");
    fprintf(Out, "\\usepackage[spanish,es-nodecimaldot]{babel}\n");
    fprintf(Out, "\\usepackage[inkscapeformat=png]{svg}\n");
    fprintf(Out, "\\usepackage{colortbl}\n");
    fprintf(Out, "\\usepackage[letterpaper, left=1.5cm, right=1.5cm, top=.5cm, bottom=2cm]{geometry}\n");
    fprintf(Out, "\n");
    fprintf(Out, "\\begin{document}\n");
    fprintf(Out, "\\pagestyle{empty}\n");
    fprintf(Out, "\\title{Secretar\\'ia de Educaci\\'on P\\'ublica\\\\\n");
    fprintf(Out, "Educaci\\'on B\\'asica del Estado de Hidalgo\\\\\n");
    fprintf(Out, "Subdirecci\\'on de Educaci\\'on Secundaria\\\\\n");
    fprintf(Out, "Zona:%s     Sector:%s\\\\\n", ZonData, SecData);
    fprintf(Out, "Ficha descriptiva del alumno: %s}\n", Nombre);
    fprintf(Out, "\\date{}\n");
    fprintf(Out, "\\author{}\n");
    fprintf(Out, "\\maketitle\n");
    fprintf(Out, "\\thispagestyle{empty}\n");
    fprintf(Out, "\n");
    fprintf(Out, "\\begin{table}[ht]\n");
    fprintf(Out, "\\centering\n");
    fprintf(Out, "\\begin{tabular}{|p{0.14 \\linewidth}|p{0.14 \\linewidth}|p{0.14 \\linewidth}|p{0.14 \\linewidth}|p{0.14 \\linewidth}|p{0.14 \\linewidth}|}\\hline\n");
    fprintf(Out, "\\multicolumn{2}{|l|}{\\cellcolor[rgb]{0.33,0.55,0.82}Escuela:}&\\multicolumn{2}{l|}{%s}& \\cellcolor[rgb]{0.33,0.55,0.82}Clave: & 13DES0045Q \\\\ \\hline\n", Escuela);
    fprintf(Out, "\\cellcolor[rgb]{0.33,0.55,0.82}Grado:&%s&\\cellcolor[rgb]{0.33,0.55,0.82}Grupo:&%s&\\cellcolor[rgb]{0.33,0.55,0.82}Ciclo Escolar:&%s\\\\ \\hline\n", Grade, Grupe, Cicle);
    fprintf(Out, "\\end{tabular}\n");
    fprintf(Out, "\\end{table}\n");
    fprintf(Out, "\n");
    fprintf(Out, "\\begin{table}[ht]\n");
    fprintf(Out, "\\begin{tabular}{|p{0.466\\linewidth}|p{0.49\\linewidth}|}\\hline\n");
    fprintf(Out, "\\multicolumn{1}{|p{0.1\\linewidth}}{\\cellcolor[rgb]{0.33,0.55,0.82}Alumno:}&%s\\\\ \\hline\n", Nombre);
    fprintf(Out, "\\multicolumn{1}{|c|}{\\cellcolor[rgb]{0.98,0.75,0}\\textbf{Fortalezas}}&\\multicolumn{1}{|c|}{\\cellcolor[rgb]{0.98,0.75,0}\\textbf{\\'Areas de oportunidad}}\\\\ \\hline\n");
    fprintf(Out, "\\begin{tabular}[l]{p{0.9\\linewidth}}\n");
    fprintf(Out, "%s\n", Te_fort);
    fprintf(Out, "\\end{tabular}\n");
    fprintf(Out, "& \n");
    fprintf(Out, "\\begin{tabular}[l]{p{0.9\\linewidth}}\n");
    fprintf(Out, "%s\n", te_op);
    fprintf(Out, "\\end{tabular}\\\\ \\hline\n");
    fprintf(Out, "\n");
    fprintf(Out, "\\multicolumn{2}{|c|}{\\cellcolor[rgb]{0,0.68,0.31}\\textbf{Recomendaciones para su consideraci\\'on en el pr\\'oximo ciclo escolar}}\\\\ \\hline\n");
    fprintf(Out, "\\multicolumn{2}{|p{0.985\\linewidth}|}{\n");
    fprintf(Out, "\\begin{tabular}[l]{p{0.985\\linewidth}}\n");
    fprintf(Out, "%s\n", Te_recom);
    fprintf(Out, "\\end{tabular}} \\\\ \\hline\n");
    fprintf(Out, "\\multicolumn{2}{c}{ }\n");
    fprintf(Out, "\\end{tabular}\n");
    fprintf(Out, "\\end{table}\n");
    fprintf(Out, "\n");
    fprintf(Out, "\\end{document}\n");
    fclose(Out);

    char command[MAX_FILENAME_LENGTH * 2];
    sprintf(command, "pdflatex %s", fname);
    system(command);
    sprintf(command, "del /s /q %s", fname);
    system(command);
    fname[strlen(fname)-3]='l';
    fname[strlen(fname)-2]='o';
    fname[strlen(fname)-1]='g';
    sprintf(command, "del /s /q %s", fname);
    system(command);
    fname[strlen(fname)-3]='a';
    fname[strlen(fname)-2]='u';
    fname[strlen(fname)-1]='x';
    sprintf(command, "del /s /q %s", fname);
    system(command);

    return NULL;
}

int main()
{
    setlocale(LC_ALL, ""); // Set locale to the user's default environment setting

    char filename[MAX_FILENAME_LENGTH];
    char line[MAX_LINE_LENGTH];
    FILE *Source;
    clock_t start, end;
    double cpu_time_used;
    pthread_t threads[100]; // Array to hold thread identifiers
    int thread_count = 0;

    printf("Introduzca el nombre de su archivo, no incluya la extensión, se asume como \".csv\"--->");
    scanf("%s", filename);
    strcat(filename, ".csv");

    Source = fopen(filename, "r");
    if (Source == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return 1;
    }

    start = clock();

    while (fgets(line, MAX_LINE_LENGTH, Source))
    {
        line[strcspn(line, "\n")] = 0;
        if (strlen(line) > 0)
        {
            pthread_create(&threads[thread_count++], NULL, func, strdup(line));
        }
    }

    for (int i = 0; i < thread_count; i++)
    {
        pthread_join(threads[i], NULL);
    }

    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("execution time: %f sec.\n", cpu_time_used);

    fclose(Source);
    return 0;
}
