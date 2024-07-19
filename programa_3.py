import os
import random
import time
from multiprocessing import Pool

vectors = 7

def Strings(cal):
    global Te_recom, Te_fort, te_op, control
    Aux_1 = ""
    if cal <= 6:
        vector(14)
        for i in range(vectors):
            NameText = "resources\Op_5-6_" + str(vec[i]) + ".txt"
            with open(NameText, "r", encoding="utf-8") as Texts:
                Aux_1 = Texts.readline().strip()
            if control == 1:
                te_op = Aux_1
                control = 0
            else:
                te_op += Aux_1

        vector(14)
        for i in range(vectors):
            NameText = "resources\Fort_5-6_" + str(vec[i]) + ".txt"
            with open(NameText, "r", encoding="utf-8") as Texts:
                Aux_1 = Texts.readline().strip()
            if control == 1:
                Te_fort = Aux_1
                control = 0
            else:
                Te_fort += Aux_1

    elif cal <= 8:
        vector(14)
        for i in range(vectors):
            NameText = "resources\Op_7-8_" + str(vec[i]) + ".txt"
            with open(NameText, "r", encoding="utf-8") as Texts:
                Aux_1 = Texts.readline().strip()
            if control == 1:
                te_op = Aux_1
                control = 0
            else:
                te_op += Aux_1

        vector(14)
        for i in range(vectors):
            NameText = "resources\Fort_7-8_" + str(vec[i]) + ".txt"
            with open(NameText, "r", encoding="utf-8") as Texts:
                Aux_1 = Texts.readline().strip()
            if control == 1:
                Te_fort = Aux_1
                control = 0
            else:
                Te_fort += Aux_1

    else:
        vector(14)
        for i in range(vectors):
            NameText = "resources\Op_7-8_" + str(vec[i]) + ".txt"
            with open(NameText, "r", encoding="utf-8") as Texts:
                Aux_1 = Texts.readline().strip()
            if control == 1:
                te_op = Aux_1
                control = 0
            else:
                te_op += Aux_1

        vector(14)
        for i in range(vectors):
            NameText = "resources\Fort_9-10_" + str(vec[i]) + ".txt"
            with open(NameText, "r", encoding="utf-8") as Texts:
                Aux_1 = Texts.readline().strip()
            if control == 1:
                Te_fort = Aux_1
                control = 0
            else:
                Te_fort += Aux_1

    vector(14)
    for i in range(5):
        NameText = "resources\Recom_" + str(vec[i]) + ".txt"
        with open(NameText, "r", encoding="utf-8") as Texts:
            Aux_1 = Texts.readline().strip()
        if control == 1:
            Te_recom = Aux_1
            control = 0
        else:
            Te_recom += Aux_1

def vector(max):
    global vec, control
    con = set()
    random.seed(time.time())
    while len(con) < vectors:
        val = random.randint(1, max)
        con.add(val)
    vec = list(con)
    
    control = 1

def func(st):
    st = str(st).split(",")
    Grade = st[3]
    Grupe = st[4]
    Cicle = st[5]
    ZonData = st[0]
    SecData = st[1]
    Escuela = st[2]
    Nombre = st[6]
    Calificacion = st[7]

    try:
        calificacion_float = float(Calificacion)
    except ValueError:
        print(f"Error: No se pudo convertir la calificación '{Calificacion}' a float.")
        return

    Strings(calificacion_float)
    fname = f"{Nombre}-{Grade}-{Grupe}.tex"
    fname = fname.replace(" ", "-")

    with open(fname, "w", encoding="utf-8") as Out:
        Nombre_print = Nombre.title()
        print(f"\x1b[31m--->{Nombre_print}<---\x1b[0m\n")
        Out.write("\\documentclass{memoir}\n")
        Out.write("\\usepackage[final]{graphicx}\n")
        Out.write("\\usepackage[spanish,es-nodecimaldot]{babel}\n")
        Out.write("\\usepackage[inkscapeformat=png]{svg}\n")
        Out.write("\\usepackage{colortbl}\n")
        Out.write("\\usepackage[letterpaper, left=1.5cm, right=1.5cm, top=.5cm, bottom=2cm]{geometry}\n")
        Out.write("\n")
        Out.write("\\begin{document}\n")
        Out.write("\\pagestyle{empty}\n")
        Out.write("\\title{Secretar\\'ia de Educaci\\'on P\\'ublica\\\\\n")
        Out.write("Educaci\\'on B\\'asica del Estado de Hidalgo\\\\\n")
        Out.write("Subdirecci\\'on de Educaci\\'on Secundaria\\\\\n")
        Out.write("Zona:%s     Sector:%s\\\\\n" % (ZonData, SecData))
        Out.write("Ficha descriptiva del alumno: %s}\n" % Nombre_print)
        Out.write("\\date{}\n")
        Out.write("\\author{}\n")
        Out.write("\\maketitle\n")
        Out.write("\\thispagestyle{empty}\n")
        Out.write("\n")
        Out.write("\\begin{table}[ht]\n")
        Out.write("\\centering\n")
        Out.write("\\begin{tabular}{|p{0.14 \\linewidth}|p{0.14 \\linewidth}|p{0.14 \\linewidth}|p{0.14 \\linewidth}|p{0.14 \\linewidth}|p{0.14 \\linewidth}|}\\hline\n")
        Out.write("\\multicolumn{2}{|l|}{\\cellcolor[rgb]{0.33,0.55,0.82}Escuela:}&\\multicolumn{2}{l|}{%s}& \\cellcolor[rgb]{0.33,0.55,0.82}Clave: & 13DES0045Q \\\\ \\hline\n" % Escuela)
        Out.write("\\cellcolor[rgb]{0.33,0.55,0.82}Grado:&%s&\\cellcolor[rgb]{0.33,0.55,0.82}Grupo:&%s&\\cellcolor[rgb]{0.33,0.55,0.82}Ciclo Escolar:&%s\\\\ \\hline\n" % (Grade, Grupe, Cicle))
        Out.write("\\end{tabular}\n")
        Out.write("\\end{table}\n")
        Out.write("\n")
        Out.write("\\begin{table}[ht]\n")
        Out.write("\\begin{tabular}{|p{0.466\\linewidth}|p{0.49\\linewidth}|}\\hline\n")
        Out.write("\\multicolumn{1}{|p{0.1\\linewidth}}{\\cellcolor[rgb]{0.33,0.55,0.82}Alumno:}&%s\\\\ \\hline\n" % Nombre_print)
        Out.write("\\multicolumn{1}{|c|}{\\cellcolor[rgb]{0.98,0.75,0}\\textbf{Fortalezas}}&\\multicolumn{1}{|c|}{\\cellcolor[rgb]{0.98,0.75,0}\\textbf{\\'Areas de oportunidad}}\\\\ \\hline\n")
        Out.write("\\begin{tabular}[l]{p{0.9\\linewidth}}\n")
        Out.write("%s\n" % Te_fort)
        Out.write("\\end{tabular}\n")
        Out.write("& \n")
        Out.write("\\begin{tabular}[l]{p{0.9\\linewidth}}\n")
        Out.write("%s\n" % te_op)
        Out.write("\\end{tabular}\\\\ \\hline\n")
        Out.write("\n")
        Out.write("\\multicolumn{2}{|c|}{\\cellcolor[rgb]{0,0.68,0.31}\\textbf{Recomendaciones para su consideraci\\'on en el pr\\'oximo ciclo escolar}}\\\\ \\hline\n")
        Out.write("\\multicolumn{2}{|p{0.985\\linewidth}|}{\n")
        Out.write("\\begin{tabular}[l]{p{0.985\\linewidth}}\n")
        Out.write("%s\n" % Te_recom)
        Out.write("\\end{tabular}} \\\\ \\hline\n")
        Out.write("\\multicolumn{2}{c}{ }\n")
        Out.write("\\end{tabular}\n")
        Out.write("\\end{table}\n")
        Out.write("\n")
        Out.write("\\end{document}\n")
        Out.close()
    os.system(f"pdflatex {fname}")
    os.system(f"del /s /q {fname}")
    os.system(f"del /s /q {fname[:-3]}log")
    os.system(f"del /s /q {fname[:-3]}aux")
    # time.sleep(0.1)

def main():
    vals = list()
    filename = input("Introduzca el nombre de su archivo, no incluya la extensión, se asume como \".csv\"--->")
    filename += ".csv"
    # print("El archivo es", filename)
    # time.sleep(0.1)

    with open(filename, "r", encoding="utf-8") as Source:
        vals = Source.read().split("\n")
    vals.pop()
    tin = time.time()
    with Pool() as pool:
        pool.map(func, vals)
    tend = time.time()

    print(f"execution time: {tend-tin} sec.")
if __name__ == "__main__":
    main()