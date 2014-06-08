#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#include "main.h"

void init() {
	//inicjalizacja shadera
	if (!(cgContext = cgCreateContext())){
		printf("Nie można utworzyć kontekstu Cg!");
		getchar();
		exit(1);
	}


	//ustawienie fragment shadera
	cgFragmentProfile = cgGLGetLatestProfile(CG_GL_FRAGMENT);
	cgGLSetOptimalOptions(cgFragmentProfile);
	if (cgFragmentProfile == CG_PROFILE_UNKNOWN){
		printf("Nie mozna zaladowac profilu Fragment Shadera!");
		getchar();
		exit(2);
	}

	//ustawienie vertex shadera
	cgVertexProfile = cgGLGetLatestProfile(CG_GL_VERTEX);
	cgGLSetOptimalOptions(cgVertexProfile);
	if (cgVertexProfile == CG_PROFILE_UNKNOWN){
		printf("Nie mozna zaladowac profilu Vertex Shadera!");
		getchar();
		exit(3);
	}


	//utworzenie programu fragment shadera
	cgFragmentProgram = cgCreateProgramFromFile(cgContext, CG_SOURCE, "fragment.cg", cgFragmentProfile, "main", 0);
	if (!cgFragmentProgram) {
		getchar();
		exit(4);
	}

	cgGLLoadProgram(cgFragmentProgram);

	//utworzenie programu vertex shadera
	cgVertexProgram = cgCreateProgramFromFile(cgContext, CG_SOURCE, "vertex.cg", cgVertexProfile, "main", 0);
	if (!cgVertexProgram)
		exit(5);

	cgGLLoadProgram(cgVertexProgram);

	//ustawienie zmiennych
	cgModelViewMatrixProj = cgGetNamedParameter(cgVertexProgram, "modelViewProj");
	cgModelViewMatrix = cgGetNamedParameter(cgVertexProgram, "modelView");
	cgPosition = cgGetNamedParameter(cgVertexProgram, "pozycja");
	cgColor = cgGetNamedParameter(cgVertexProgram, "kolorr");
	cgFogColor = cgGetNamedParameter(cgFragmentProgram, "kolorMgly");
	cgFogDensity = cgGetNamedParameter(cgVertexProgram, "gestoscMgly");

	puts("--Pomyslnie zainicjalizowano shadery--");

	glEnable(GL_FRAGMENT_PROGRAM_ARB);

	//wlaczenie funkcji z rozszerzeniami tekstur do obslugi shaderow
	//glActiveTextureARB = (PFNGLACTIVETEXTUREARBPROC)
	//	wglGetProcAddress("glActiveTextureARB");
}

void licz(int mnoznik, char znak)
{
	int licznikobrotu;
	int i, j, k, l;
	for (licznikobrotu = 0; licznikobrotu < 15; licznikobrotu++)
	{
		kat = mnoznik*PI / 180;
		kopiujKostke();
		for (k = 0; k < 6; k++)
		{
			for (i = 0; i < 9; i++)
			{
				for (j = 0; j < 4; j++)
				{
					for (l = 0; l < 3; l++)
					{
						switch (znak)
						{
						case 'z':
						case 'x':
							if ((k == 0) | (k == 1))//|((k==2)&(i%3==2)))
							{
								wall[k][2][i].pkt[j].x = wall_kopia[k][2][i].pkt[j].x*cos(kat) - wall_kopia[k][2][i].pkt[j].y*sin(kat);
								wall[k][2][i].pkt[j].y = wall_kopia[k][2][i].pkt[j].x*sin(kat) + wall_kopia[k][2][i].pkt[j].y*cos(kat);
							}
							if (((k == 4)&(i > 5)) | ((k == 3)&(i % 3 == 0)))//|((k==2)&(i%3==2)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							if (((k == 5)&(i > 5)) | ((k == 2)&(i % 3 == 0)))//((( k==3)&(i%3==2))|((k==4)&(i<3)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							break;
						case 'q':
						case 'w':
							if ((k == 0) | (k == 1))
							{
								wall[k][0][i].pkt[j].x = wall_kopia[k][0][i].pkt[j].x*cos(kat) - wall_kopia[k][0][i].pkt[j].y*sin(kat);
								wall[k][0][i].pkt[j].y = wall_kopia[k][0][i].pkt[j].x*sin(kat) + wall_kopia[k][0][i].pkt[j].y*cos(kat);
							}
							if (((k == 5)&(i < 3)) | ((k == 2)&(i % 3 == 2)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							if (((k == 3)&(i % 3 == 2)) | ((k == 4)&(i < 3)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							break;
						case 's':
						case 'a':
							if ((k == 0) | (k == 1))
							{
								wall[k][1][i].pkt[j].x = wall_kopia[k][1][i].pkt[j].x*cos(kat) - wall_kopia[k][1][i].pkt[j].y*sin(kat);
								wall[k][1][i].pkt[j].y = wall_kopia[k][1][i].pkt[j].x*sin(kat) + wall_kopia[k][1][i].pkt[j].y*cos(kat);
							}
							if (((k == 5)&(i > 2)&(i<6)) | ((k == 2)&(i % 3 == 1)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							if (((k == 3)&(i % 3 == 1)) | ((k == 4)&(i>2)&(i < 6)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							break;
						case 'r':
						case 'e':
							if ((k == 2) | (k == 3))
							{
								wall[k][0][i].pkt[j].z = wall_kopia[k][0][i].pkt[j].z*cos(kat) - wall_kopia[k][0][i].pkt[j].y*sin(kat);
								wall[k][0][i].pkt[j].y = wall_kopia[k][0][i].pkt[j].z*sin(kat) + wall_kopia[k][0][i].pkt[j].y*cos(kat);
							}
							if (((k == 5)&((i % 3) == 2)) | ((k == 0)&((i % 3) == 2)))
							{
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].z*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].z*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							if (((k == 4)&((i % 3) == 2)) | ((k == 1)&((i % 3) == 2)))
							{
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].z*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].z*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							break;
						case 'f':
						case 'd':
							if ((k == 2) | (k == 3))
							{
								wall[k][1][i].pkt[j].z = wall_kopia[k][1][i].pkt[j].z*cos(kat) - wall_kopia[k][1][i].pkt[j].y*sin(kat);
								wall[k][1][i].pkt[j].y = wall_kopia[k][1][i].pkt[j].z*sin(kat) + wall_kopia[k][1][i].pkt[j].y*cos(kat);
							}
							if (((k == 5)&((i % 3) == 1)) | ((k == 0)&((i % 3) == 1)))
							{
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].z*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].z*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							if (((k == 4)&((i % 3) == 1)) | ((k == 1)&((i % 3) == 1)))
							{
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].z*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].z*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							break;
						case 'v':
						case 'c':
							if ((k == 2) | (k == 3))
							{
								wall[k][2][i].pkt[j].z = wall_kopia[k][2][i].pkt[j].z*cos(kat) - wall_kopia[k][2][i].pkt[j].y*sin(kat);
								wall[k][2][i].pkt[j].y = wall_kopia[k][2][i].pkt[j].z*sin(kat) + wall_kopia[k][2][i].pkt[j].y*cos(kat);
							}
							if (((k == 4)&((i % 3) == 0)) | ((k == 1)&((i % 3) == 0)))
							{
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].z*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].z*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							if (((k == 5)&((i % 3) == 0)) | ((k == 0)&((i % 3) == 0)))
							{
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].z*cos(kat) - wall_kopia[k][l][i].pkt[j].y*sin(kat);
								wall[k][l][i].pkt[j].y = wall_kopia[k][l][i].pkt[j].z*sin(kat) + wall_kopia[k][l][i].pkt[j].y*cos(kat);
							}
							break;
						case 't':
						case 'y':
							if ((k == 4) | (k == 5))
							{
								wall[k][0][i].pkt[j].x = wall_kopia[k][0][i].pkt[j].x*cos(kat) - wall_kopia[k][0][i].pkt[j].z*sin(kat);
								wall[k][0][i].pkt[j].z = wall_kopia[k][0][i].pkt[j].x*sin(kat) + wall_kopia[k][0][i].pkt[j].z*cos(kat);
							}
							if (((k == 2)&(i < 3)) | ((k == 0)&(i < 3)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].z*sin(kat);
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].z*cos(kat);
							}
							if (((k == 1)&(i < 3)) | ((k == 3)&(i < 3)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].z*sin(kat);
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].z*cos(kat);
							}
							break;
						case 'g':
						case 'h':
							if ((k == 4) | (k == 5))
							{
								wall[k][1][i].pkt[j].x = wall_kopia[k][1][i].pkt[j].x*cos(kat) - wall_kopia[k][1][i].pkt[j].z*sin(kat);
								wall[k][1][i].pkt[j].z = wall_kopia[k][1][i].pkt[j].x*sin(kat) + wall_kopia[k][1][i].pkt[j].z*cos(kat);
							}
							if (((k == 2)&(i > 2)&(i<6)) | ((k == 0)&(i>2)*(i<6)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].z*sin(kat);
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].z*cos(kat);
							}
							if (((k == 1)&(i>2)&(i<6)) | ((k == 3)&(i>2)&(i < 6)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].z*sin(kat);
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].z*cos(kat);
							}
							break;
						case 'b':
						case 'n':
							if ((k == 4) | (k == 5))
							{
								wall[k][2][i].pkt[j].x = wall_kopia[k][2][i].pkt[j].x*cos(kat) - wall_kopia[k][2][i].pkt[j].z*sin(kat);
								wall[k][2][i].pkt[j].z = wall_kopia[k][2][i].pkt[j].x*sin(kat) + wall_kopia[k][2][i].pkt[j].z*cos(kat);
							}
							if (((k == 1)&(i > 5)) | ((k == 3)&(i > 5)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].z*sin(kat);
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].z*cos(kat);
							}
							if (((k == 2)&(i > 5)) | ((k == 0)&(i > 5)))
							{
								wall[k][l][i].pkt[j].x = wall_kopia[k][l][i].pkt[j].x*cos(kat) - wall_kopia[k][l][i].pkt[j].z*sin(kat);
								wall[k][l][i].pkt[j].z = wall_kopia[k][l][i].pkt[j].x*sin(kat) + wall_kopia[k][l][i].pkt[j].z*cos(kat);
							}
							break;
						}
					}
				}
			}
		}
		Sleep(slip);

		Display();
	}
}
//wspolrzedne x,y,z  danego punktu
void kopiujScianyZewnetrzne()
{
	int i, j;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 9; j++)
			kolor_zew_kopia[i][j] = kolor_zew[i][j];
}
void zmienTabliceKolorow2()
{
	kolor_zew[1][2] = ref[1][0][0];
	kolor_zew[1][1] = ref[1][0][1];
	kolor_zew[1][0] = ref[1][0][2];
	kolor_zew[1][5] = ref[1][1][0];
	kolor_zew[1][4] = ref[1][1][1];
	kolor_zew[1][3] = ref[1][1][2];
	kolor_zew[1][8] = ref[1][2][0];
	kolor_zew[1][7] = ref[1][2][1];
	kolor_zew[1][6] = ref[1][2][2];

	kolor_zew[5][2] = ref[5][0][0];
	kolor_zew[5][1] = ref[5][0][1];
	kolor_zew[5][0] = ref[5][0][2];
	kolor_zew[5][5] = ref[5][1][0];
	kolor_zew[5][4] = ref[5][1][1];
	kolor_zew[5][3] = ref[5][1][2];
	kolor_zew[5][8] = ref[5][2][0];
	kolor_zew[5][7] = ref[5][2][1];
	kolor_zew[5][6] = ref[5][2][2];

	kolor_zew[3][2] = ref[3][0][0];
	kolor_zew[3][5] = ref[3][0][1];
	kolor_zew[3][8] = ref[3][0][2];
	kolor_zew[3][1] = ref[3][1][0];
	kolor_zew[3][4] = ref[3][1][1];
	kolor_zew[3][7] = ref[3][1][2];
	kolor_zew[3][0] = ref[3][2][0];
	kolor_zew[3][3] = ref[3][2][1];
	kolor_zew[3][6] = ref[3][2][2];

	kolor_zew[4][0] = ref[4][0][0];
	kolor_zew[4][1] = ref[4][0][1];
	kolor_zew[4][2] = ref[4][0][2];
	kolor_zew[4][3] = ref[4][1][0];
	kolor_zew[4][4] = ref[4][1][1];
	kolor_zew[4][5] = ref[4][1][2];
	kolor_zew[4][6] = ref[4][2][0];
	kolor_zew[4][7] = ref[4][2][1];
	kolor_zew[4][8] = ref[4][2][2];

	kolor_zew[2][8] = ref[2][0][0];
	kolor_zew[2][5] = ref[2][0][1];
	kolor_zew[2][2] = ref[2][0][2];
	kolor_zew[2][7] = ref[2][1][0];
	kolor_zew[2][4] = ref[2][1][1];
	kolor_zew[2][1] = ref[2][1][2];
	kolor_zew[2][6] = ref[2][2][0];
	kolor_zew[2][3] = ref[2][2][1];
	kolor_zew[2][0] = ref[2][2][2];

	kolor_zew[0][8] = ref[0][0][0];
	kolor_zew[0][7] = ref[0][0][1];
	kolor_zew[0][6] = ref[0][0][2];
	kolor_zew[0][5] = ref[0][1][0];
	kolor_zew[0][4] = ref[0][1][1];
	kolor_zew[0][3] = ref[0][1][2];
	kolor_zew[0][2] = ref[0][2][0];
	kolor_zew[0][1] = ref[0][2][1];
	kolor_zew[0][0] = ref[0][2][2];

	kolor_zew_kopia[1][2] = ref_kopia[1][0][0];
	kolor_zew_kopia[1][1] = ref_kopia[1][0][1];
	kolor_zew_kopia[1][0] = ref_kopia[1][0][2];
	kolor_zew_kopia[1][5] = ref_kopia[1][1][0];
	kolor_zew_kopia[1][4] = ref_kopia[1][1][1];
	kolor_zew_kopia[1][3] = ref_kopia[1][1][2];
	kolor_zew_kopia[1][8] = ref_kopia[1][2][0];
	kolor_zew_kopia[1][7] = ref_kopia[1][2][1];
	kolor_zew_kopia[1][6] = ref_kopia[1][2][2];

	kolor_zew_kopia[5][2] = ref_kopia[5][0][0];
	kolor_zew_kopia[5][1] = ref_kopia[5][0][1];
	kolor_zew_kopia[5][0] = ref_kopia[5][0][2];
	kolor_zew_kopia[5][5] = ref_kopia[5][1][0];
	kolor_zew_kopia[5][4] = ref_kopia[5][1][1];
	kolor_zew_kopia[5][3] = ref_kopia[5][1][2];
	kolor_zew_kopia[5][8] = ref_kopia[5][2][0];
	kolor_zew_kopia[5][7] = ref_kopia[5][2][1];
	kolor_zew_kopia[5][6] = ref_kopia[5][2][2];

	kolor_zew_kopia[3][2] = ref_kopia[3][0][0];
	kolor_zew_kopia[3][5] = ref_kopia[3][0][1];
	kolor_zew_kopia[3][8] = ref_kopia[3][0][2];
	kolor_zew_kopia[3][1] = ref_kopia[3][1][0];
	kolor_zew_kopia[3][4] = ref_kopia[3][1][1];
	kolor_zew_kopia[3][7] = ref_kopia[3][1][2];
	kolor_zew_kopia[3][0] = ref_kopia[3][2][0];
	kolor_zew_kopia[3][3] = ref_kopia[3][2][1];
	kolor_zew_kopia[3][6] = ref_kopia[3][2][2];

	kolor_zew_kopia[4][0] = ref_kopia[4][0][0];
	kolor_zew_kopia[4][1] = ref_kopia[4][0][1];
	kolor_zew_kopia[4][2] = ref_kopia[4][0][2];
	kolor_zew_kopia[4][3] = ref_kopia[4][1][0];
	kolor_zew_kopia[4][4] = ref_kopia[4][1][1];
	kolor_zew_kopia[4][5] = ref_kopia[4][1][2];
	kolor_zew_kopia[4][6] = ref_kopia[4][2][0];
	kolor_zew_kopia[4][7] = ref_kopia[4][2][1];
	kolor_zew_kopia[4][8] = ref_kopia[4][2][2];

	kolor_zew_kopia[2][8] = ref_kopia[2][0][0];
	kolor_zew_kopia[2][5] = ref_kopia[2][0][1];
	kolor_zew_kopia[2][2] = ref_kopia[2][0][2];
	kolor_zew_kopia[2][7] = ref_kopia[2][1][0];
	kolor_zew_kopia[2][4] = ref_kopia[2][1][1];
	kolor_zew_kopia[2][1] = ref_kopia[2][1][2];
	kolor_zew_kopia[2][6] = ref_kopia[2][2][0];
	kolor_zew_kopia[2][3] = ref_kopia[2][2][1];
	kolor_zew_kopia[2][0] = ref_kopia[2][2][2];

	kolor_zew_kopia[0][8] = ref_kopia[0][0][0];
	kolor_zew_kopia[0][7] = ref_kopia[0][0][1];
	kolor_zew_kopia[0][6] = ref_kopia[0][0][2];
	kolor_zew_kopia[0][5] = ref_kopia[0][1][0];
	kolor_zew_kopia[0][4] = ref_kopia[0][1][1];
	kolor_zew_kopia[0][3] = ref_kopia[0][1][2];
	kolor_zew_kopia[0][2] = ref_kopia[0][2][0];
	kolor_zew_kopia[0][1] = ref_kopia[0][2][1];
	kolor_zew_kopia[0][0] = ref_kopia[0][2][2];

}


void zmienTabliceKolorow1()
{
	ref[1][0][0] = kolor_zew[1][2];
	ref[1][0][1] = kolor_zew[1][1];
	ref[1][0][2] = kolor_zew[1][0];
	ref[1][1][0] = kolor_zew[1][5];
	ref[1][1][1] = kolor_zew[1][4];
	ref[1][1][2] = kolor_zew[1][3];
	ref[1][2][0] = kolor_zew[1][8];
	ref[1][2][1] = kolor_zew[1][7];
	ref[1][2][2] = kolor_zew[1][6];

	ref[5][0][0] = kolor_zew[5][2];
	ref[5][0][1] = kolor_zew[5][1];
	ref[5][0][2] = kolor_zew[5][0];
	ref[5][1][0] = kolor_zew[5][5];
	ref[5][1][1] = kolor_zew[5][4];
	ref[5][1][2] = kolor_zew[5][3];
	ref[5][2][0] = kolor_zew[5][8];
	ref[5][2][1] = kolor_zew[5][7];
	ref[5][2][2] = kolor_zew[5][6];

	ref[3][0][0] = kolor_zew[3][2];
	ref[3][0][1] = kolor_zew[3][5];
	ref[3][0][2] = kolor_zew[3][8];
	ref[3][1][0] = kolor_zew[3][1];
	ref[3][1][1] = kolor_zew[3][4];
	ref[3][1][2] = kolor_zew[3][7];
	ref[3][2][0] = kolor_zew[3][0];
	ref[3][2][1] = kolor_zew[3][3];
	ref[3][2][2] = kolor_zew[3][6];

	ref[4][0][0] = kolor_zew[4][0];
	ref[4][0][1] = kolor_zew[4][1];
	ref[4][0][2] = kolor_zew[4][2];
	ref[4][1][0] = kolor_zew[4][3];
	ref[4][1][1] = kolor_zew[4][4];
	ref[4][1][2] = kolor_zew[4][5];
	ref[4][2][0] = kolor_zew[4][6];
	ref[4][2][1] = kolor_zew[4][7];
	ref[4][2][2] = kolor_zew[4][8];

	ref[2][0][0] = kolor_zew[2][8];
	ref[2][0][1] = kolor_zew[2][5];
	ref[2][0][2] = kolor_zew[2][2];
	ref[2][1][0] = kolor_zew[2][7];
	ref[2][1][1] = kolor_zew[2][4];
	ref[2][1][2] = kolor_zew[2][1];
	ref[2][2][0] = kolor_zew[2][6];
	ref[2][2][1] = kolor_zew[2][3];
	ref[2][2][2] = kolor_zew[2][0];

	ref[0][0][0] = kolor_zew[0][8];
	ref[0][0][1] = kolor_zew[0][7];
	ref[0][0][2] = kolor_zew[0][6];
	ref[0][1][0] = kolor_zew[0][5];
	ref[0][1][1] = kolor_zew[0][4];
	ref[0][1][2] = kolor_zew[0][3];
	ref[0][2][0] = kolor_zew[0][2];
	ref[0][2][1] = kolor_zew[0][1];
	ref[0][2][2] = kolor_zew[0][0];

	ref_kopia[1][0][0] = kolor_zew_kopia[1][2];
	ref_kopia[1][0][1] = kolor_zew_kopia[1][1];
	ref_kopia[1][0][2] = kolor_zew_kopia[1][0];
	ref_kopia[1][1][0] = kolor_zew_kopia[1][5];
	ref_kopia[1][1][1] = kolor_zew_kopia[1][4];
	ref_kopia[1][1][2] = kolor_zew_kopia[1][3];
	ref_kopia[1][2][0] = kolor_zew_kopia[1][8];
	ref_kopia[1][2][1] = kolor_zew_kopia[1][7];
	ref_kopia[1][2][2] = kolor_zew_kopia[1][6];

	ref_kopia[5][0][0] = kolor_zew_kopia[5][2];
	ref_kopia[5][0][1] = kolor_zew_kopia[5][1];
	ref_kopia[5][0][2] = kolor_zew_kopia[5][0];
	ref_kopia[5][1][0] = kolor_zew_kopia[5][5];
	ref_kopia[5][1][1] = kolor_zew_kopia[5][4];
	ref_kopia[5][1][2] = kolor_zew_kopia[5][3];
	ref_kopia[5][2][0] = kolor_zew_kopia[5][8];
	ref_kopia[5][2][1] = kolor_zew_kopia[5][7];
	ref_kopia[5][2][2] = kolor_zew_kopia[5][6];

	ref_kopia[3][0][0] = kolor_zew_kopia[3][2];
	ref_kopia[3][0][1] = kolor_zew_kopia[3][5];
	ref_kopia[3][0][2] = kolor_zew_kopia[3][8];
	ref_kopia[3][1][0] = kolor_zew_kopia[3][1];
	ref_kopia[3][1][1] = kolor_zew_kopia[3][4];
	ref_kopia[3][1][2] = kolor_zew_kopia[3][7];
	ref_kopia[3][2][0] = kolor_zew_kopia[3][0];
	ref_kopia[3][2][1] = kolor_zew_kopia[3][3];
	ref_kopia[3][2][2] = kolor_zew_kopia[3][6];

	ref_kopia[4][0][0] = kolor_zew_kopia[4][0];
	ref_kopia[4][0][1] = kolor_zew_kopia[4][1];
	ref_kopia[4][0][2] = kolor_zew_kopia[4][2];
	ref_kopia[4][1][0] = kolor_zew_kopia[4][3];
	ref_kopia[4][1][1] = kolor_zew_kopia[4][4];
	ref_kopia[4][1][2] = kolor_zew_kopia[4][5];
	ref_kopia[4][2][0] = kolor_zew_kopia[4][6];
	ref_kopia[4][2][1] = kolor_zew_kopia[4][7];
	ref_kopia[4][2][2] = kolor_zew_kopia[4][8];

	ref_kopia[2][0][0] = kolor_zew_kopia[2][8];
	ref_kopia[2][0][1] = kolor_zew_kopia[2][5];
	ref_kopia[2][0][2] = kolor_zew_kopia[2][2];
	ref_kopia[2][1][0] = kolor_zew_kopia[2][7];
	ref_kopia[2][1][1] = kolor_zew_kopia[2][4];
	ref_kopia[2][1][2] = kolor_zew_kopia[2][1];
	ref_kopia[2][2][0] = kolor_zew_kopia[2][6];
	ref_kopia[2][2][1] = kolor_zew_kopia[2][3];
	ref_kopia[2][2][2] = kolor_zew_kopia[2][0];

	ref_kopia[0][0][0] = kolor_zew_kopia[0][8];
	ref_kopia[0][0][1] = kolor_zew_kopia[0][7];
	ref_kopia[0][0][2] = kolor_zew_kopia[0][6];
	ref_kopia[0][1][0] = kolor_zew_kopia[0][5];
	ref_kopia[0][1][1] = kolor_zew_kopia[0][4];
	ref_kopia[0][1][2] = kolor_zew_kopia[0][3];
	ref_kopia[0][2][0] = kolor_zew_kopia[0][2];
	ref_kopia[0][2][1] = kolor_zew_kopia[0][1];
	ref_kopia[0][2][2] = kolor_zew_kopia[0][0];

}

//funkcja pobiera symbol koloru i zwraca dany Kolor
const GLfloat *wezKolor(int tab)
{
	const GLfloat *kolor = Brown;
	switch (tab)
	{
	case 0:
	{
		kolor = White;
		break;
	}
	case 1:
	{
		kolor = Yellow;
		break;
	}
	case 2:
	{
		kolor = Green;
		break;
	}
	case 3:
	{
		kolor = Blue;
		break;
	}
	case 4:
	{
		kolor = Orange;
		break;
	}
	case 5:
	{
		kolor = Red;
		break;
	}
	case 6:
	{
		kolor = Purple;
		break;
	}
	case 7:
	{
		kolor = Pink;
		break;
	}
	case 8:
	{
		kolor = Silver;
		break;
	}
	case 9:
	{
		kolor = Brown;
		break;
	}
	}
	return kolor;
}

int  dajKolor(const GLfloat *tab)
{
	int kolor;
	if (tab == White)
		kolor = 0;
	else if (tab == Yellow)
		kolor = 1;
	else if (tab == Green)
		kolor = 2;
	else if (tab == Blue)
		kolor = 3;
	else if (tab == Orange)
		kolor = 4;
	else if (tab == Red)
		kolor = 5;
	else if (tab == Black)
		kolor = 888;
	return kolor;
}

void inicjujKolory(Sciana sciana[6][3][9], int tab[6][9])
{
	int i, j;
	for (i = 0; i < 9; i++)
		for (j = 0; j < 6; j++)
			if ((j == 0) | (j == 2) | (j == 5))
				sciana[j][0][i].kolor = wezKolor(tab[j][i]);
			else if ((j == 1) | (j == 3) | (j == 4))
				sciana[j][2][i].kolor = wezKolor(tab[j][i]);
}

// funkcja generuj1ca scene 3D
void rysujSciane(Sciana scianka)
{
	glColor3fv(scianka.kolor);
	glVertex3f(scianka.pkt[0].x, scianka.pkt[0].y, scianka.pkt[0].z);
	glVertex3f(scianka.pkt[1].x, scianka.pkt[1].y, scianka.pkt[1].z);
	glVertex3f(scianka.pkt[2].x, scianka.pkt[2].y, scianka.pkt[2].z);
	glVertex3f(scianka.pkt[3].x, scianka.pkt[3].y, scianka.pkt[3].z);
}

void inicjujWspolrzedne()
{
	int j, k, l;
	for (j = 0; j < 3; j++)
		for (k = 0; k < 9; k++)
			for (l = 0; l < 4; l++)
			{
				wall[2][j][k].pkt[l].x = wall[0][j][k].pkt[l].z;
				wall[2][j][k].pkt[l].z = wall[0][j][k].pkt[l].x;
				wall[2][j][k].pkt[l].y = wall[0][j][k].pkt[l].y;
				wall[3][j][k].pkt[l].x = wall[1][j][k].pkt[l].z;
				wall[3][j][k].pkt[l].z = wall[1][j][k].pkt[l].x;
				wall[3][j][k].pkt[l].y = wall[1][j][k].pkt[l].y;
				wall[4][j][k].pkt[l].x = wall[1][j][k].pkt[l].x;
				wall[4][j][k].pkt[l].z = wall[1][j][k].pkt[l].y;
				wall[4][j][k].pkt[l].y = wall[1][j][k].pkt[l].z;
				wall[5][j][k].pkt[l].x = wall[0][j][k].pkt[l].x;
				wall[5][j][k].pkt[l].z = wall[0][j][k].pkt[l].y;
				wall[5][j][k].pkt[l].y = wall[0][j][k].pkt[l].z;
			}
}

void rysujKostke()
{
	int i, j, k;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 9; k++)
				rysujSciane(wall[i][j][k]);
}

void kopiujKostke()
{
	int i, j, k, l;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 9; k++)
				for (l = 0; l < 4; l++)
				{
					wall_kopia[i][j][k].pkt[l].x = wall[i][j][k].pkt[l].x;
					wall_kopia[i][j][k].pkt[l].y = wall[i][j][k].pkt[l].y;
					wall_kopia[i][j][k].pkt[l].z = wall[i][j][k].pkt[l].z;
				}
}

void kopiujKostke2()
{
	int i, j, k, l;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 9; k++)
				for (l = 0; l < 4; l++)
				{
					wall[i][j][k].pkt[l].x = wall_kopia2[i][j][k].pkt[l].x;
					wall[i][j][k].pkt[l].y = wall_kopia2[i][j][k].pkt[l].y;
					wall[i][j][k].pkt[l].z = wall_kopia2[i][j][k].pkt[l].z;
				}
}

void kopiujKostke3()
{
	int i, j, k, l;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 3; j++)
			for (k = 0; k < 9; k++)
			{
				for (l = 0; l < 4; l++)
				{
					wall_kopia2[i][j][k].pkt[l].x = wall[i][j][k].pkt[l].x;
					wall_kopia2[i][j][k].pkt[l].y = wall[i][j][k].pkt[l].y;
					wall_kopia2[i][j][k].pkt[l].z = wall[i][j][k].pkt[l].z;
				}
				wall_kopia2[i][j][k].kolor = wall[i][j][k].kolor;
			}
}

void Display()
{
	cgGLEnableProfile(cgVertexProfile);
	cgGLEnableProfile(cgFragmentProfile);
	cgGLBindProgram(cgVertexProgram);
	cgGLBindProgram(cgFragmentProgram);

	glClearColor(0.35, 0.35, 0.35, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -(near + far) / 2);
	if (menu == 1)
	{
		glRotatef(rotatex, 1.0, 0, 0);
		glRotatef(rotatey, 0, 1.0, 0);
		glRotatef(rotatez, 0, 0, 1.0);
	}
	// niewielkie powiekszenie szeocianu
	glScalef(1.15, 1.15, 1.15);

	// rysowanie szeocianu - 12 trójk1tów
	inicjujKolory(wall, kolor_zew);
	/////////
	if (gratulacje == 1)
	{
		cgGLDisableProfile(cgVertexProfile);
		cgGLDisableProfile(cgFragmentProfile);
		glDisable(GL_TEXTURE_1D);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glBindTexture(GL_TEXTURE_2D, tekstura[24]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-8, graty2, 5.9);
		glTexCoord2f(0, 1);
		glVertex3f(-8, graty1, 5.9);
		glTexCoord2f(1, 1);
		glVertex3f(8, graty1, 5.9);
		glTexCoord2f(1, 0);
		glVertex3f(8, graty2, 5.9);
		glEnd();
		glPopMatrix();


	}
	/////////
	if (menu == 1)
	{
		cgGLEnableProfile(cgVertexProfile);
		cgGLEnableProfile(cgFragmentProfile);

		//Wlaczenie programow Cg
		cgGLBindProgram(cgVertexProgram);
		cgGLBindProgram(cgFragmentProgram);

		//Przekazanie zmiennych do shadera
		cgGLSetParameter3f(cgPosition, 0, 0, 28);
		//cgGLSetParameter3f(cgColor,1.0,0.0,0.0);
		cgGLSetStateMatrixParameter(cgModelViewMatrix, CG_GL_MODELVIEW_MATRIX, CG_GL_MATRIX_IDENTITY);
		cgGLSetStateMatrixParameter(cgModelViewMatrixProj, CG_GL_MODELVIEW_PROJECTION_MATRIX, CG_GL_MATRIX_IDENTITY);
		cgGLSetParameter3f(cgFogColor, 0, 0, 1);
		cgGLSetParameter1f(cgFogDensity, Density);
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_QUADS);
		rysujKostke();
		glEnd();
	}
	else if (menu == 0)
	{
		cgGLDisableProfile(cgVertexProfile);
		cgGLDisableProfile(cgFragmentProfile);
		
		glDisable(GL_TEXTURE_1D);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glBindTexture(GL_TEXTURE_2D, tekstura[0]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-8, -8, 5.9);
		glTexCoord2f(0, 1);
		glVertex3f(-8, 8, 5.9);
		glTexCoord2f(1, 1);
		glVertex3f(8, 8, 5.9);
		glTexCoord2f(1, 0);
		glVertex3f(8, -8, 5.9);
		glEnd();
		glPopMatrix();

		if (akt1 == 0)
			glBindTexture(GL_TEXTURE_2D, tekstura[1]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[4]);
		glPushMatrix();
		glTranslatef(0, 1.5, 0);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();

		if (akt2 == 0)
			glBindTexture(GL_TEXTURE_2D, tekstura[2]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[5]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();

		if (akt3 == 0)
			glBindTexture(GL_TEXTURE_2D, tekstura[3]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[6]);

		glPushMatrix();
		glTranslatef(0, -1.5, 0);
		glBegin(GL_QUADS);

		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);


	}
	else if (menu == 2)
	{
		cgGLDisableProfile(cgVertexProfile);
		cgGLDisableProfile(cgFragmentProfile);
		glDisable(GL_TEXTURE_1D);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glBindTexture(GL_TEXTURE_2D, tekstura[7]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-8, -8, 5.9);
		glTexCoord2f(0, 1);
		glVertex3f(-8, 8, 5.9);
		glTexCoord2f(1, 1);
		glVertex3f(8, 8, 5.9);
		glTexCoord2f(1, 0);
		glVertex3f(8, -8, 5.9);
		glEnd();
		glPopMatrix();

		////////start
		if (akt4 == 0)
			glBindTexture(GL_TEXTURE_2D, tekstura[8]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[9]);
		glPushMatrix();
		glTranslatef(0, 1.5, 0);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();

		if (akt5 == 0)
			glBindTexture(GL_TEXTURE_2D, tekstura[10]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[11]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();

		if (akt6 == 0)
			glBindTexture(GL_TEXTURE_2D, tekstura[12]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[13]);

		glPushMatrix();
		glTranslatef(0, -1.5, 0);
		glBegin(GL_QUADS);

		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);


		//////// stop
	}
	else if (menu == 3)
	{
		cgGLDisableProfile(cgVertexProfile);
		cgGLDisableProfile(cgFragmentProfile);
		glDisable(GL_TEXTURE_1D);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glBindTexture(GL_TEXTURE_2D, tekstura[14]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-8, -8, 5.9);
		glTexCoord2f(0, 1);
		glVertex3f(-8, 8, 5.9);
		glTexCoord2f(1, 1);
		glVertex3f(8, 8, 5.9);
		glTexCoord2f(1, 0);
		glVertex3f(8, -8, 5.9);
		glEnd();
		glPopMatrix();

		////////start
		if ((akt7 == 1) | (menu_dzwieki == 0))
			glBindTexture(GL_TEXTURE_2D, tekstura[17]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[16]);
		glPushMatrix();
		glTranslatef(0, 1.5, 0);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();

		if ((akt8 == 1) | (menu_dzwieki == 1))
			glBindTexture(GL_TEXTURE_2D, tekstura[19]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[18]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();

		if (akt9 == 0)
			glBindTexture(GL_TEXTURE_2D, tekstura[12]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[13]);

		glPushMatrix();
		glTranslatef(0, -1.5, 0);
		glBegin(GL_QUADS);

		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);


		//////// stop
	}

	else if (menu == 4)
	{
		cgGLDisableProfile(cgVertexProfile);
		cgGLDisableProfile(cgFragmentProfile);
		glDisable(GL_TEXTURE_1D);
		glEnable(GL_TEXTURE_2D);
		glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
		glBindTexture(GL_TEXTURE_2D, tekstura[15]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-8, -8, 5.9);
		glTexCoord2f(0, 1);
		glVertex3f(-8, 8, 5.9);
		glTexCoord2f(1, 1);
		glVertex3f(8, 8, 5.9);
		glTexCoord2f(1, 0);
		glVertex3f(8, -8, 5.9);
		glEnd();
		glPopMatrix();

		////////start
		if ((akt10 == 1) | (menu_latwy == 0))
			glBindTexture(GL_TEXTURE_2D, tekstura[21]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[20]);
		glPushMatrix();
		glTranslatef(0, 1.5, 0);
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();

		if ((akt11 == 1) | (menu_latwy == 1))
			glBindTexture(GL_TEXTURE_2D, tekstura[23]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[22]);
		glPushMatrix();
		glBegin(GL_QUADS);
		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();

		if (akt12 == 0)
			glBindTexture(GL_TEXTURE_2D, tekstura[12]);
		else
			glBindTexture(GL_TEXTURE_2D, tekstura[13]);

		glPushMatrix();
		glTranslatef(0, -1.5, 0);
		glBegin(GL_QUADS);

		glTexCoord2f(0, 0);
		glVertex3f(-1.6, -0.5, 6);
		glTexCoord2f(0, 1);
		glVertex3f(-1.6, 0.5, 6);
		glTexCoord2f(1, 1);
		glVertex3f(1.6, 0.5, 6);
		glTexCoord2f(1, 0);
		glVertex3f(1.6, -0.5, 6);
		glEnd();
		glPopMatrix();
		glDisable(GL_TEXTURE_2D);


		//////// stop
	}
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);

	// wyowietlenie sk3adowych globalnego owiat3a otaczaj1cego
	GLfloat rgba[4];
	glColor3fv(Black);

	glGetFloatv(GL_LIGHT_MODEL_AMBIENT, rgba);

	glLoadIdentity();
	glTranslatef(0, 0, -near);
	// narysowanie napisu

	glutSwapBuffers();
}

void Reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (aspect == ASPECT_1_1)
	{
		if (width < height && width > 0)
			glFrustum(left, right, bottom * height / width, top * height / width, near, far);
		else if (width >= height && height > 0)
			glFrustum(left * width / height, right * width / height, bottom, top, near, far);
	}
	else
		glFrustum(left, right, bottom, top, near, far);
	Display();
}

// obs3uga klawiatury
void transformacja(int ref[6][3][3])
{
	zmienTabliceKolorow1();
}

void qfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[0][6] = kolor_zew_kopia[0][0];
	kolor_zew[0][3] = kolor_zew_kopia[0][1];
	kolor_zew[0][0] = kolor_zew_kopia[0][2];
	kolor_zew[0][7] = kolor_zew_kopia[0][3];
	kolor_zew[0][4] = kolor_zew_kopia[0][4];
	kolor_zew[0][1] = kolor_zew_kopia[0][5];
	kolor_zew[0][8] = kolor_zew_kopia[0][6];
	kolor_zew[0][5] = kolor_zew_kopia[0][7];
	kolor_zew[0][2] = kolor_zew_kopia[0][8];
	kolor_zew[3][8] = kolor_zew_kopia[5][0];
	kolor_zew[3][5] = kolor_zew_kopia[5][1];
	kolor_zew[3][2] = kolor_zew_kopia[5][2];
	kolor_zew[5][0] = kolor_zew_kopia[2][2];
	kolor_zew[5][1] = kolor_zew_kopia[2][5];
	kolor_zew[5][2] = kolor_zew_kopia[2][8];
	kolor_zew[2][2] = kolor_zew_kopia[4][2];
	kolor_zew[2][5] = kolor_zew_kopia[4][1];
	kolor_zew[2][8] = kolor_zew_kopia[4][0];
	kolor_zew[4][2] = kolor_zew_kopia[3][8];
	kolor_zew[4][1] = kolor_zew_kopia[3][5];
	kolor_zew[4][0] = kolor_zew_kopia[3][2];
	Display();
	transformacja(ref);

}
void wfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[0][0] = kolor_zew_kopia[0][6];
	kolor_zew[0][1] = kolor_zew_kopia[0][3];
	kolor_zew[0][2] = kolor_zew_kopia[0][0];
	kolor_zew[0][3] = kolor_zew_kopia[0][7];
	kolor_zew[0][4] = kolor_zew_kopia[0][4];
	kolor_zew[0][5] = kolor_zew_kopia[0][1];
	kolor_zew[0][6] = kolor_zew_kopia[0][8];
	kolor_zew[0][7] = kolor_zew_kopia[0][5];
	kolor_zew[0][8] = kolor_zew_kopia[0][2];

	kolor_zew[5][0] = kolor_zew_kopia[3][8];
	kolor_zew[5][1] = kolor_zew_kopia[3][5];
	kolor_zew[5][2] = kolor_zew_kopia[3][2];
	kolor_zew[2][2] = kolor_zew_kopia[5][0];
	kolor_zew[2][5] = kolor_zew_kopia[5][1];
	kolor_zew[2][8] = kolor_zew_kopia[5][2];
	kolor_zew[4][2] = kolor_zew_kopia[2][2];
	kolor_zew[4][1] = kolor_zew_kopia[2][5];
	kolor_zew[4][0] = kolor_zew_kopia[2][8];
	kolor_zew[3][8] = kolor_zew_kopia[4][2];
	kolor_zew[3][5] = kolor_zew_kopia[4][1];
	kolor_zew[3][2] = kolor_zew_kopia[4][0];

	Display();
	transformacja(ref);
}
void afunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();


	kolor_zew[3][7] = kolor_zew_kopia[5][3];
	kolor_zew[3][4] = kolor_zew_kopia[5][4];
	kolor_zew[3][1] = kolor_zew_kopia[5][5];
	kolor_zew[5][3] = kolor_zew_kopia[2][1];
	kolor_zew[5][4] = kolor_zew_kopia[2][4];
	kolor_zew[5][5] = kolor_zew_kopia[2][7];
	kolor_zew[2][1] = kolor_zew_kopia[4][5];
	kolor_zew[2][4] = kolor_zew_kopia[4][4];
	kolor_zew[2][7] = kolor_zew_kopia[4][3];
	kolor_zew[4][5] = kolor_zew_kopia[3][7];
	kolor_zew[4][4] = kolor_zew_kopia[3][4];
	kolor_zew[4][3] = kolor_zew_kopia[3][1];
	Display();
	transformacja(ref);
}
void sfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();


	kolor_zew[5][3] = kolor_zew_kopia[3][7];
	kolor_zew[5][4] = kolor_zew_kopia[3][4];
	kolor_zew[5][5] = kolor_zew_kopia[3][1];
	kolor_zew[2][1] = kolor_zew_kopia[5][3];
	kolor_zew[2][4] = kolor_zew_kopia[5][4];
	kolor_zew[2][7] = kolor_zew_kopia[5][5];
	kolor_zew[4][5] = kolor_zew_kopia[2][1];
	kolor_zew[4][4] = kolor_zew_kopia[2][4];
	kolor_zew[4][3] = kolor_zew_kopia[2][7];
	kolor_zew[3][7] = kolor_zew_kopia[4][5];
	kolor_zew[3][4] = kolor_zew_kopia[4][4];
	kolor_zew[3][1] = kolor_zew_kopia[4][3];
	Display();
	transformacja(ref);
}
void zfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[1][0] = kolor_zew_kopia[1][2];
	kolor_zew[1][1] = kolor_zew_kopia[1][5];
	kolor_zew[1][2] = kolor_zew_kopia[1][8];
	kolor_zew[1][3] = kolor_zew_kopia[1][1];
	kolor_zew[1][4] = kolor_zew_kopia[1][4];
	kolor_zew[1][5] = kolor_zew_kopia[1][7];
	kolor_zew[1][6] = kolor_zew_kopia[1][0];
	kolor_zew[1][7] = kolor_zew_kopia[1][3];
	kolor_zew[1][8] = kolor_zew_kopia[1][6];

	kolor_zew[3][6] = kolor_zew_kopia[5][6];
	kolor_zew[3][3] = kolor_zew_kopia[5][7];
	kolor_zew[3][0] = kolor_zew_kopia[5][8];
	kolor_zew[5][6] = kolor_zew_kopia[2][0];
	kolor_zew[5][7] = kolor_zew_kopia[2][3];
	kolor_zew[5][8] = kolor_zew_kopia[2][6];
	kolor_zew[2][0] = kolor_zew_kopia[4][8];
	kolor_zew[2][3] = kolor_zew_kopia[4][7];
	kolor_zew[2][6] = kolor_zew_kopia[4][6];
	kolor_zew[4][8] = kolor_zew_kopia[3][6];
	kolor_zew[4][7] = kolor_zew_kopia[3][3];
	kolor_zew[4][6] = kolor_zew_kopia[3][0];
	Display();
	transformacja(ref);
}
void xfunkcja(unsigned char key)
{
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();

	kolor_zew[1][2] = kolor_zew_kopia[1][0];
	kolor_zew[1][5] = kolor_zew_kopia[1][1];
	kolor_zew[1][8] = kolor_zew_kopia[1][2];
	kolor_zew[1][1] = kolor_zew_kopia[1][3];
	kolor_zew[1][4] = kolor_zew_kopia[1][4];
	kolor_zew[1][7] = kolor_zew_kopia[1][5];
	kolor_zew[1][0] = kolor_zew_kopia[1][6];
	kolor_zew[1][3] = kolor_zew_kopia[1][7];
	kolor_zew[1][6] = kolor_zew_kopia[1][8];

	kolor_zew[5][6] = kolor_zew_kopia[3][6];
	kolor_zew[5][7] = kolor_zew_kopia[3][3];
	kolor_zew[5][8] = kolor_zew_kopia[3][0];
	kolor_zew[2][0] = kolor_zew_kopia[5][6];
	kolor_zew[2][3] = kolor_zew_kopia[5][7];
	kolor_zew[2][6] = kolor_zew_kopia[5][8];
	kolor_zew[4][8] = kolor_zew_kopia[2][0];
	kolor_zew[4][7] = kolor_zew_kopia[2][3];
	kolor_zew[4][6] = kolor_zew_kopia[2][6];
	kolor_zew[3][6] = kolor_zew_kopia[4][8];
	kolor_zew[3][3] = kolor_zew_kopia[4][7];
	kolor_zew[3][0] = kolor_zew_kopia[4][6];

	//kolor_zew[6][9]

	//printf("lalala");

	Display();
	transformacja(ref);
}
void efunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[2][8] = kolor_zew_kopia[2][2];
	kolor_zew[2][5] = kolor_zew_kopia[2][1];
	kolor_zew[2][2] = kolor_zew_kopia[2][0];
	kolor_zew[2][7] = kolor_zew_kopia[2][5];
	kolor_zew[2][4] = kolor_zew_kopia[2][4];
	kolor_zew[2][1] = kolor_zew_kopia[2][3];
	kolor_zew[2][6] = kolor_zew_kopia[2][8];
	kolor_zew[2][3] = kolor_zew_kopia[2][7];
	kolor_zew[2][0] = kolor_zew_kopia[2][6];
	kolor_zew[0][8] = kolor_zew_kopia[5][2];
	kolor_zew[0][5] = kolor_zew_kopia[5][5];
	kolor_zew[0][2] = kolor_zew_kopia[5][8];
	kolor_zew[5][2] = kolor_zew_kopia[1][2];
	kolor_zew[5][5] = kolor_zew_kopia[1][5];
	kolor_zew[5][8] = kolor_zew_kopia[1][8];
	kolor_zew[1][2] = kolor_zew_kopia[4][8];
	kolor_zew[1][5] = kolor_zew_kopia[4][5];
	kolor_zew[1][8] = kolor_zew_kopia[4][2];
	kolor_zew[4][8] = kolor_zew_kopia[0][8];
	kolor_zew[4][5] = kolor_zew_kopia[0][5];
	kolor_zew[4][2] = kolor_zew_kopia[0][2];

	Display();
	transformacja(ref);
}
void rfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[2][2] = kolor_zew_kopia[2][8];
	kolor_zew[2][1] = kolor_zew_kopia[2][5];
	kolor_zew[2][0] = kolor_zew_kopia[2][2];
	kolor_zew[2][5] = kolor_zew_kopia[2][7];
	kolor_zew[2][4] = kolor_zew_kopia[2][4];
	kolor_zew[2][3] = kolor_zew_kopia[2][1];
	kolor_zew[2][8] = kolor_zew_kopia[2][6];
	kolor_zew[2][7] = kolor_zew_kopia[2][3];
	kolor_zew[2][6] = kolor_zew_kopia[2][0];

	kolor_zew[5][2] = kolor_zew_kopia[0][8];
	kolor_zew[5][5] = kolor_zew_kopia[0][5];
	kolor_zew[5][8] = kolor_zew_kopia[0][2];
	kolor_zew[1][2] = kolor_zew_kopia[5][2];
	kolor_zew[1][5] = kolor_zew_kopia[5][5];
	kolor_zew[1][8] = kolor_zew_kopia[5][8];
	kolor_zew[4][8] = kolor_zew_kopia[1][2];
	kolor_zew[4][5] = kolor_zew_kopia[1][5];
	kolor_zew[4][2] = kolor_zew_kopia[1][8];
	kolor_zew[0][8] = kolor_zew_kopia[4][8];
	kolor_zew[0][5] = kolor_zew_kopia[4][5];
	kolor_zew[0][2] = kolor_zew_kopia[4][2];
	Display();
	transformacja(ref);
}
void dfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[0][7] = kolor_zew_kopia[5][1];
	kolor_zew[0][4] = kolor_zew_kopia[5][4];
	kolor_zew[0][1] = kolor_zew_kopia[5][7];
	kolor_zew[5][1] = kolor_zew_kopia[1][1];
	kolor_zew[5][4] = kolor_zew_kopia[1][4];
	kolor_zew[5][7] = kolor_zew_kopia[1][7];
	kolor_zew[1][1] = kolor_zew_kopia[4][7];
	kolor_zew[1][4] = kolor_zew_kopia[4][4];
	kolor_zew[1][7] = kolor_zew_kopia[4][1];
	kolor_zew[4][7] = kolor_zew_kopia[0][7];
	kolor_zew[4][4] = kolor_zew_kopia[0][4];
	kolor_zew[4][1] = kolor_zew_kopia[0][1];
	Display();
	transformacja(ref);
}
void ffunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[5][1] = kolor_zew_kopia[0][7];
	kolor_zew[5][4] = kolor_zew_kopia[0][4];
	kolor_zew[5][7] = kolor_zew_kopia[0][1];
	kolor_zew[1][1] = kolor_zew_kopia[5][1];
	kolor_zew[1][4] = kolor_zew_kopia[5][4];
	kolor_zew[1][7] = kolor_zew_kopia[5][7];
	kolor_zew[4][7] = kolor_zew_kopia[1][1];
	kolor_zew[4][4] = kolor_zew_kopia[1][4];
	kolor_zew[4][1] = kolor_zew_kopia[1][7];
	kolor_zew[0][7] = kolor_zew_kopia[4][7];
	kolor_zew[0][4] = kolor_zew_kopia[4][4];
	kolor_zew[0][1] = kolor_zew_kopia[4][1];
	Display();
	transformacja(ref);
}
void cfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[3][2] = kolor_zew_kopia[3][0];
	kolor_zew[3][5] = kolor_zew_kopia[3][1];
	kolor_zew[3][8] = kolor_zew_kopia[3][2];
	kolor_zew[3][1] = kolor_zew_kopia[3][3];
	kolor_zew[3][4] = kolor_zew_kopia[3][4];
	kolor_zew[3][7] = kolor_zew_kopia[3][5];
	kolor_zew[3][0] = kolor_zew_kopia[3][6];
	kolor_zew[3][3] = kolor_zew_kopia[3][7];
	kolor_zew[3][6] = kolor_zew_kopia[3][8];
	kolor_zew[0][6] = kolor_zew_kopia[5][0];
	kolor_zew[0][3] = kolor_zew_kopia[5][3];
	kolor_zew[0][0] = kolor_zew_kopia[5][6];
	kolor_zew[5][0] = kolor_zew_kopia[1][0];
	kolor_zew[5][3] = kolor_zew_kopia[1][3];
	kolor_zew[5][6] = kolor_zew_kopia[1][6];
	kolor_zew[1][0] = kolor_zew_kopia[4][6];
	kolor_zew[1][3] = kolor_zew_kopia[4][3];
	kolor_zew[1][6] = kolor_zew_kopia[4][0];
	kolor_zew[4][6] = kolor_zew_kopia[0][6];
	kolor_zew[4][3] = kolor_zew_kopia[0][3];
	kolor_zew[4][0] = kolor_zew_kopia[0][0];


	Display();
	transformacja(ref);
}
void vfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[3][0] = kolor_zew_kopia[3][2];
	kolor_zew[3][1] = kolor_zew_kopia[3][5];
	kolor_zew[3][2] = kolor_zew_kopia[3][8];
	kolor_zew[3][3] = kolor_zew_kopia[3][1];
	kolor_zew[3][4] = kolor_zew_kopia[3][4];
	kolor_zew[3][5] = kolor_zew_kopia[3][7];
	kolor_zew[3][6] = kolor_zew_kopia[3][0];
	kolor_zew[3][7] = kolor_zew_kopia[3][3];
	kolor_zew[3][8] = kolor_zew_kopia[3][6];

	kolor_zew[5][0] = kolor_zew_kopia[0][6];
	kolor_zew[5][3] = kolor_zew_kopia[0][3];
	kolor_zew[5][6] = kolor_zew_kopia[0][0];
	kolor_zew[1][0] = kolor_zew_kopia[5][0];
	kolor_zew[1][3] = kolor_zew_kopia[5][3];
	kolor_zew[1][6] = kolor_zew_kopia[5][6];
	kolor_zew[4][6] = kolor_zew_kopia[1][0];
	kolor_zew[4][3] = kolor_zew_kopia[1][3];
	kolor_zew[4][0] = kolor_zew_kopia[1][6];
	kolor_zew[0][6] = kolor_zew_kopia[4][6];
	kolor_zew[0][3] = kolor_zew_kopia[4][3];
	kolor_zew[0][0] = kolor_zew_kopia[4][0];
	Display();
	transformacja(ref);
}
void tfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[5][0] = kolor_zew_kopia[5][2];
	kolor_zew[5][1] = kolor_zew_kopia[5][5];
	kolor_zew[5][2] = kolor_zew_kopia[5][8];
	kolor_zew[5][3] = kolor_zew_kopia[5][1];
	kolor_zew[5][4] = kolor_zew_kopia[5][4];
	kolor_zew[5][5] = kolor_zew_kopia[5][7];
	kolor_zew[5][6] = kolor_zew_kopia[5][0];
	kolor_zew[5][7] = kolor_zew_kopia[5][3];
	kolor_zew[5][8] = kolor_zew_kopia[5][6];
	kolor_zew[1][0] = kolor_zew_kopia[3][2];
	kolor_zew[1][1] = kolor_zew_kopia[3][1];
	kolor_zew[1][2] = kolor_zew_kopia[3][0];
	kolor_zew[2][0] = kolor_zew_kopia[1][0];
	kolor_zew[2][1] = kolor_zew_kopia[1][1];
	kolor_zew[2][2] = kolor_zew_kopia[1][2];
	kolor_zew[0][2] = kolor_zew_kopia[2][0];
	kolor_zew[0][1] = kolor_zew_kopia[2][1];
	kolor_zew[0][0] = kolor_zew_kopia[2][2];
	kolor_zew[3][2] = kolor_zew_kopia[0][2];
	kolor_zew[3][1] = kolor_zew_kopia[0][1];
	kolor_zew[3][0] = kolor_zew_kopia[0][0];
	Display();
	transformacja(ref);
}
void yfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[5][2] = kolor_zew_kopia[5][0];
	kolor_zew[5][5] = kolor_zew_kopia[5][1];
	kolor_zew[5][8] = kolor_zew_kopia[5][2];
	kolor_zew[5][1] = kolor_zew_kopia[5][3];
	kolor_zew[5][4] = kolor_zew_kopia[5][4];
	kolor_zew[5][7] = kolor_zew_kopia[5][5];
	kolor_zew[5][0] = kolor_zew_kopia[5][6];
	kolor_zew[5][3] = kolor_zew_kopia[5][7];
	kolor_zew[5][6] = kolor_zew_kopia[5][8];
	kolor_zew[3][2] = kolor_zew_kopia[1][0];
	kolor_zew[3][1] = kolor_zew_kopia[1][1];
	kolor_zew[3][0] = kolor_zew_kopia[1][2];
	kolor_zew[1][0] = kolor_zew_kopia[2][0];
	kolor_zew[1][1] = kolor_zew_kopia[2][1];
	kolor_zew[1][2] = kolor_zew_kopia[2][2];
	kolor_zew[2][0] = kolor_zew_kopia[0][2];
	kolor_zew[2][1] = kolor_zew_kopia[0][1];
	kolor_zew[2][2] = kolor_zew_kopia[0][0];
	kolor_zew[0][2] = kolor_zew_kopia[3][2];
	kolor_zew[0][1] = kolor_zew_kopia[3][1];
	kolor_zew[0][0] = kolor_zew_kopia[3][0];
	Display();
	transformacja(ref);
}
void gfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[1][3] = kolor_zew_kopia[3][5];
	kolor_zew[1][4] = kolor_zew_kopia[3][4];
	kolor_zew[1][5] = kolor_zew_kopia[3][3];
	kolor_zew[2][3] = kolor_zew_kopia[1][3];
	kolor_zew[2][4] = kolor_zew_kopia[1][4];
	kolor_zew[2][5] = kolor_zew_kopia[1][5];
	kolor_zew[0][5] = kolor_zew_kopia[2][3];
	kolor_zew[0][4] = kolor_zew_kopia[2][4];
	kolor_zew[0][3] = kolor_zew_kopia[2][5];
	kolor_zew[3][5] = kolor_zew_kopia[0][5];
	kolor_zew[3][4] = kolor_zew_kopia[0][4];
	kolor_zew[3][3] = kolor_zew_kopia[0][3];
	Display();
	transformacja(ref);
}
void hfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[3][5] = kolor_zew_kopia[1][3];
	kolor_zew[3][4] = kolor_zew_kopia[1][4];
	kolor_zew[3][3] = kolor_zew_kopia[1][5];
	kolor_zew[1][3] = kolor_zew_kopia[2][3];
	kolor_zew[1][4] = kolor_zew_kopia[2][4];
	kolor_zew[1][5] = kolor_zew_kopia[2][5];
	kolor_zew[2][3] = kolor_zew_kopia[0][5];
	kolor_zew[2][4] = kolor_zew_kopia[0][4];
	kolor_zew[2][5] = kolor_zew_kopia[0][3];
	kolor_zew[0][5] = kolor_zew_kopia[3][5];
	kolor_zew[0][4] = kolor_zew_kopia[3][4];
	kolor_zew[0][3] = kolor_zew_kopia[3][3];

	Display();
	transformacja(ref);
}
void bfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[4][0] = kolor_zew_kopia[4][2];
	kolor_zew[4][1] = kolor_zew_kopia[4][5];
	kolor_zew[4][2] = kolor_zew_kopia[4][8];
	kolor_zew[4][3] = kolor_zew_kopia[4][1];
	kolor_zew[4][4] = kolor_zew_kopia[4][4];
	kolor_zew[4][5] = kolor_zew_kopia[4][7];
	kolor_zew[4][6] = kolor_zew_kopia[4][0];
	kolor_zew[4][7] = kolor_zew_kopia[4][3];
	kolor_zew[4][8] = kolor_zew_kopia[4][6];

	kolor_zew[1][6] = kolor_zew_kopia[3][8];
	kolor_zew[1][7] = kolor_zew_kopia[3][7];
	kolor_zew[1][8] = kolor_zew_kopia[3][6];
	kolor_zew[2][6] = kolor_zew_kopia[1][6];
	kolor_zew[2][7] = kolor_zew_kopia[1][7];
	kolor_zew[2][8] = kolor_zew_kopia[1][8];
	kolor_zew[0][8] = kolor_zew_kopia[2][6];
	kolor_zew[0][7] = kolor_zew_kopia[2][7];
	kolor_zew[0][6] = kolor_zew_kopia[2][8];
	kolor_zew[3][8] = kolor_zew_kopia[0][8];
	kolor_zew[3][7] = kolor_zew_kopia[0][7];
	kolor_zew[3][6] = kolor_zew_kopia[0][6];
	Display();
	transformacja(ref);
}
void nfunkcja(unsigned char key)
{
	kopiujKostke3();
	licz(-6, key);
	kopiujKostke2();
	kopiujScianyZewnetrzne();
	kolor_zew[4][2] = kolor_zew_kopia[4][0];
	kolor_zew[4][5] = kolor_zew_kopia[4][1];
	kolor_zew[4][8] = kolor_zew_kopia[4][2];
	kolor_zew[4][1] = kolor_zew_kopia[4][3];
	kolor_zew[4][4] = kolor_zew_kopia[4][4];
	kolor_zew[4][7] = kolor_zew_kopia[4][5];
	kolor_zew[4][0] = kolor_zew_kopia[4][6];
	kolor_zew[4][3] = kolor_zew_kopia[4][7];
	kolor_zew[4][6] = kolor_zew_kopia[4][8];
	kolor_zew[3][8] = kolor_zew_kopia[1][6];
	kolor_zew[3][7] = kolor_zew_kopia[1][7];
	kolor_zew[3][6] = kolor_zew_kopia[1][8];
	kolor_zew[1][6] = kolor_zew_kopia[2][6];
	kolor_zew[1][7] = kolor_zew_kopia[2][7];
	kolor_zew[1][8] = kolor_zew_kopia[2][8];
	kolor_zew[2][6] = kolor_zew_kopia[0][8];
	kolor_zew[2][7] = kolor_zew_kopia[0][7];
	kolor_zew[2][8] = kolor_zew_kopia[0][6];
	kolor_zew[0][8] = kolor_zew_kopia[3][8];
	kolor_zew[0][7] = kolor_zew_kopia[3][7];
	kolor_zew[0][6] = kolor_zew_kopia[3][6];
	Display();
	transformacja(ref);
}

void szukajBialej(Sciana sciana[6][3][9])
{
	int i, j;
	int tasciana;
	for (i = 0; i < 6; i++)
	{
		for (j = 0; j < 3; j++)
		{
			tasciana = dajKolor(sciana[i][j][4].kolor);

			if (tasciana == 1)
			{
				switch (i)
				{
				case 0:
				{
					ffunkcja('f');
					break;
				}
				case 1:
				{
					dfunkcja('d');
					break;
				}
				case 2:
				{
					afunkcja('a');
					break;
				}
				case 3:
				{
					sfunkcja('s');
					break;
				}
				case 4:
				{
					sfunkcja('s');
					sfunkcja('s');
					break;
				}
				case 5:
				{
					break;
				}
				}

			}
		}
	}
}
void szukajBialej2(Sciana sciana[6][3][9])
{
	int j;
	int mam = 0;
	int licz;
	//int tasciana;
	//for(i=0; i<6; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (dajKolor(sciana[0][j][1].kolor) == 0)
			{
				wfunkcja('w');
			}
			if (dajKolor(sciana[2][j][1].kolor) == 0)
			{
				gfunkcja('g');
			}
			if (dajKolor(sciana[1][j][1].kolor) == 0)
			{
				zfunkcja('z');
			}
			if (dajKolor(sciana[3][j][1].kolor) == 0)
			{
				vfunkcja('v');
			}
			for (licz = 0; licz < 4; licz++)
			{
				if (dajKolor(sciana[1][j][3].kolor) == 0)
				{
					mam = 1;
					cfunkcja('c');
				}
				else if (dajKolor(sciana[1][j][7].kolor) == 0)
				{
					mam = 1;
					nfunkcja('n');
					vfunkcja('v');
					gfunkcja('g');
					bfunkcja('b');
					cfunkcja('c');
				}
				else if (dajKolor(sciana[1][j][5].kolor) == 0)
				{
					mam = 1;
					gfunkcja('g');
					gfunkcja('g');
					vfunkcja('v');
				}
				if (mam == 1)
				{
					yfunkcja('y');
					mam = 0;
				}
				gfunkcja('g');
				bfunkcja('b');


			}

			if (dajKolor(sciana[4][j][3].kolor) == 0)
			{
				mam = 1;
				vfunkcja('v');
				vfunkcja('v');
			}
			else if (dajKolor(sciana[4][j][7].kolor) == 0)
			{
				mam = 1;
				nfunkcja('n');
				vfunkcja('v');
				vfunkcja('v');

			}
			else if (dajKolor(sciana[4][j][5].kolor) == 0)
			{
				mam = 1;
				bfunkcja('b');
				bfunkcja('b');
				vfunkcja('v');
				vfunkcja('v');

			}
			else if (dajKolor(sciana[4][j][1].kolor) == 0)
			{
				mam = 1;
				bfunkcja('b');
				vfunkcja('v');
				vfunkcja('v');

			}
			if (mam == 1)
			{
				yfunkcja('y');
				mam = 0;
			}
		}
	}
}
void bialyKrzyz(Sciana sciana[6][3][9])
{
	int i;

	for (i = 0; i < 4; i++)
	{
		while ((dajKolor(sciana[1][2][1].kolor) != dajKolor(sciana[1][2][4].kolor)) | (dajKolor(sciana[5][0][7].kolor) != 0))
		{
			tfunkcja('t');
		}
		zfunkcja('z');
		zfunkcja('z');
		tfunkcja('t');
		gfunkcja('g');
		bfunkcja('b');
	}
	cfunkcja('c');
	cfunkcja('c');
	dfunkcja('d');
	dfunkcja('d');
	efunkcja('e');
	efunkcja('e');
}
void naroznikiBialej(Sciana sciana[6][3][9])
{
	int i = 0;
	int next = 0;
	int szukam;
	int naroznik[12];
	naroznik[0] = dajKolor(wall[5][0][0].kolor);
	naroznik[1] = dajKolor(wall[5][0][6].kolor);
	naroznik[2] = dajKolor(wall[5][0][8].kolor);
	naroznik[3] = dajKolor(wall[5][0][2].kolor);
	naroznik[4] = dajKolor(wall[2][0][0].kolor);
	naroznik[5] = dajKolor(wall[1][2][0].kolor);
	naroznik[6] = dajKolor(wall[3][2][2].kolor);
	naroznik[7] = dajKolor(wall[0][0][2].kolor);
	naroznik[8] = dajKolor(wall[2][0][1].kolor);
	naroznik[9] = dajKolor(wall[1][2][1].kolor);
	naroznik[10] = dajKolor(wall[3][2][1].kolor);
	naroznik[11] = dajKolor(wall[0][0][1].kolor);
	while ((naroznik[0] != 0) | (naroznik[1] != 0) | (naroznik[2] != 0) | (naroznik[3] != 0) |
		(naroznik[4] != naroznik[8]) |
		(naroznik[5] != naroznik[9]) |
		(naroznik[6] != naroznik[10]) |
		(naroznik[7] != naroznik[11]))


	{
		//licznikpetli++;

		dajKolor(sciana[1][2][1].kolor), dajKolor(sciana[1][2][0].kolor),
			dajKolor(sciana[5][0][7].kolor), dajKolor(sciana[5][0][6].kolor),
			dajKolor(sciana[3][2][1].kolor), dajKolor(sciana[3][2][0].kolor);
		next = 0;
		if ((dajKolor(sciana[1][2][1].kolor) == dajKolor(sciana[1][2][0].kolor))&
			(dajKolor(sciana[5][0][7].kolor) == dajKolor(sciana[5][0][6].kolor))&
			(dajKolor(sciana[3][2][1].kolor) == dajKolor(sciana[3][2][0].kolor)))
		{
			next = 1;
		}

		else if ((dajKolor(sciana[1][2][1].kolor) == dajKolor(sciana[5][0][6].kolor))&
			(dajKolor(sciana[5][0][7].kolor) == dajKolor(sciana[3][2][0].kolor))&
			(dajKolor(sciana[3][2][1].kolor) == dajKolor(sciana[1][2][0].kolor)))
		{
			vfunkcja('v');
			bfunkcja('b');
			cfunkcja('c');
			nfunkcja('n');
			nfunkcja('n');
			zfunkcja('z');
			bfunkcja('b');
			xfunkcja('x');
			next = 1;
		}
		else if ((dajKolor(sciana[1][2][1].kolor) == dajKolor(sciana[3][2][0].kolor))&
			(dajKolor(sciana[5][0][7].kolor) == dajKolor(sciana[1][2][0].kolor))&
			(dajKolor(sciana[3][2][1].kolor) == dajKolor(sciana[5][0][6].kolor)))
		{
			zfunkcja('z');
			nfunkcja('n');
			xfunkcja('x');
			bfunkcja('b');
			bfunkcja('b');
			vfunkcja('v');
			nfunkcja('n');
			cfunkcja('c');
			next = 1;
		}
		else if (next == 0)
		{
			for (i = 0; i < 4; i++)
			{
				if ((dajKolor(sciana[1][2][6].kolor) == dajKolor(sciana[1][2][1].kolor))&
					(dajKolor(sciana[4][2][6].kolor) == dajKolor(sciana[3][2][1].kolor))&
					(dajKolor(sciana[3][2][6].kolor) == dajKolor(sciana[5][0][7].kolor)))
				{
					nfunkcja('n');
					zfunkcja('z');
					bfunkcja('b');
					xfunkcja('x');
					next = 1;
					break;
				}
				else if
					((dajKolor(sciana[1][2][6].kolor) == dajKolor(sciana[5][0][7].kolor))&
					(dajKolor(sciana[4][2][6].kolor) == dajKolor(sciana[1][2][1].kolor))&
					(dajKolor(sciana[3][2][6].kolor) == dajKolor(sciana[3][2][1].kolor)))
				{
					bfunkcja('b');
					vfunkcja('v');
					nfunkcja('n');
					cfunkcja('c');
					next = 1;
					break;
				}
				else if
					((dajKolor(sciana[1][2][6].kolor) == dajKolor(sciana[3][2][1].kolor))&
					(dajKolor(sciana[4][2][6].kolor) == dajKolor(sciana[5][0][7].kolor))&
					(dajKolor(sciana[3][2][6].kolor) == dajKolor(sciana[1][2][1].kolor)))
				{
					vfunkcja('v');
					bfunkcja('b');
					bfunkcja('b');
					cfunkcja('c');
					nfunkcja('n');
					nfunkcja('n');
					zfunkcja('z');
					bfunkcja('b');
					xfunkcja('x');
					next = 1;
					break;
				}
				else
				{
					bfunkcja('b');
					szukam++;
				}
			}
		}
		if (szukam == 4)
		{
			vfunkcja('v');
			bfunkcja('b');
			cfunkcja('c');
			nfunkcja('n');
			next = 1;
		}
		szukam = 0;
		if (next == 1)
		{
			tfunkcja('t');
			gfunkcja('g');
			bfunkcja('b');
		}
		naroznik[0] = dajKolor(wall[5][0][0].kolor);
		naroznik[1] = dajKolor(wall[5][0][6].kolor);
		naroznik[2] = dajKolor(wall[5][0][8].kolor);
		naroznik[3] = dajKolor(wall[5][0][2].kolor);
		naroznik[4] = dajKolor(wall[2][0][0].kolor);
		naroznik[5] = dajKolor(wall[1][2][0].kolor);
		naroznik[6] = dajKolor(wall[3][2][2].kolor);
		naroznik[7] = dajKolor(wall[0][0][2].kolor);
		naroznik[8] = dajKolor(wall[2][0][1].kolor);
		naroznik[9] = dajKolor(wall[1][2][1].kolor);
		naroznik[10] = dajKolor(wall[3][2][1].kolor);
		naroznik[11] = dajKolor(wall[0][0][1].kolor);
	}
	xfunkcja('x');
	sfunkcja('s');
	wfunkcja('w');
}

///////////

void drugaWarstwa2(Sciana sciana[6][3][9])
{
	int mam = 0, licznik = 0;
	int z3 = dajKolor(wall[1][2][3].kolor);
	int z4 = dajKolor(wall[1][2][4].kolor);
	int z1 = dajKolor(wall[1][2][1].kolor);
	int z7 = dajKolor(wall[1][2][7].kolor);
	int n3 = dajKolor(wall[3][2][3].kolor);
	int c4 = dajKolor(wall[5][0][4].kolor);
	int c1 = dajKolor(wall[5][0][1].kolor);
	int c7 = dajKolor(wall[5][0][7].kolor);
	int p4 = dajKolor(wall[4][2][4].kolor);
	int p1 = dajKolor(wall[4][2][1].kolor);
	int p7 = dajKolor(wall[4][2][7].kolor);
	int b4 = dajKolor(wall[0][0][4].kolor);
	int b1 = dajKolor(wall[0][0][1].kolor);
	int b7 = dajKolor(wall[0][0][7].kolor);
	while ((z4 != z1) | (z4 != z7) | (c4 != c1) | (c4 != c7) | (b4 != b1) | (b4 != b7) | (p4 != p1) | (p4 != p7))
	{
		licznik = 0;
		mam = 0;
		while (!((z1 == z4)&(c7 == c4)))
		{

			if (((z4 == z3)&(n3 == c4)) | ((z4 == c7)&(z1 == c4)))
			{
				vfunkcja('v');
				yfunkcja('y');
				cfunkcja('c');
				tfunkcja('t');
				cfunkcja('c');
				zfunkcja('z');
				vfunkcja('v');
				xfunkcja('x');

				mam = 1;
			}
			else if (((z4 == z7)&(c4 == p7)) | ((z4 == p7)&(z7 == c4)))
			{
				cfunkcja('c');
				nfunkcja('n');
				vfunkcja('v');
				bfunkcja('b');
				vfunkcja('v');
				xfunkcja('x');
				cfunkcja('c');
				zfunkcja('z');
				mam = 1;
			}
			else if ((z4 == n3)&(z3 == c4))
			{
				rfunkcja('r');
				ffunkcja('f');
				cfunkcja('c');
				nfunkcja('n');
				vfunkcja('v');
				bfunkcja('b');
				vfunkcja('v');
				xfunkcja('x');
				cfunkcja('c');
				zfunkcja('z');
				efunkcja('e');
				dfunkcja('d');
				mam = 1;
			}
			else if ((z4 == n3)&(z3 == p4))
			{
				efunkcja('e');
				dfunkcja('d');
				mam = 1;
			}
			if (mam == 1)
			{
				vfunkcja('v');
				mam = 0;
			}
			else if (mam == 0)
			{
				vfunkcja('v');
				licznik++;
			}

			if (licznik == 4)
			{
				licznik = 0;
				if (((z4 == c1)&(c4 == b1)) | ((c1 == c4)&(b1 == z4)))
				{
					rfunkcja('r');
					ffunkcja('f');
					vfunkcja('v');
					vfunkcja('v');
					yfunkcja('y');
					cfunkcja('c');
					tfunkcja('t');
					cfunkcja('c');
					zfunkcja('z');
					vfunkcja('v');
					xfunkcja('x');
					efunkcja('e');
					dfunkcja('d');
					cfunkcja('c');
				}
				else if (((p1 == z4)&(b7 == c4)) | ((z4 == b7)&(c4 == p1)))
				{
					efunkcja('e');
					dfunkcja('d');
					cfunkcja('c');
					efunkcja('e');
					dfunkcja('d');
					cfunkcja('c');
					vfunkcja('v');
					yfunkcja('y');
					cfunkcja('c');
					tfunkcja('t');
					cfunkcja('c');
					zfunkcja('z');
					vfunkcja('v');
					xfunkcja('x');
					rfunkcja('r');
					ffunkcja('f');
					vfunkcja('v');
					rfunkcja('r');
					ffunkcja('f');
					vfunkcja('v');
				}
			}
			z3 = dajKolor(wall[1][2][3].kolor);
			z4 = dajKolor(wall[1][2][4].kolor);
			z1 = dajKolor(wall[1][2][1].kolor);
			z7 = dajKolor(wall[1][2][7].kolor);
			n3 = dajKolor(wall[3][2][3].kolor);
			c4 = dajKolor(wall[5][0][4].kolor);
			c1 = dajKolor(wall[5][0][1].kolor);
			c7 = dajKolor(wall[5][0][7].kolor);
			p4 = dajKolor(wall[4][2][4].kolor);
			p1 = dajKolor(wall[4][2][1].kolor);
			p7 = dajKolor(wall[4][2][7].kolor);
			b4 = dajKolor(wall[0][0][4].kolor);
			b1 = dajKolor(wall[0][0][1].kolor);
			b7 = dajKolor(wall[0][0][7].kolor);
		}
		rfunkcja('r');
		ffunkcja('f');
		vfunkcja('v');
		z3 = dajKolor(wall[1][2][3].kolor);
		z4 = dajKolor(wall[1][2][4].kolor);
		z1 = dajKolor(wall[1][2][1].kolor);
		z7 = dajKolor(wall[1][2][7].kolor);
		n3 = dajKolor(wall[3][2][3].kolor);
		c4 = dajKolor(wall[5][0][4].kolor);
		c1 = dajKolor(wall[5][0][1].kolor);
		c7 = dajKolor(wall[5][0][7].kolor);
		p4 = dajKolor(wall[4][2][4].kolor);
		p1 = dajKolor(wall[4][2][1].kolor);
		p7 = dajKolor(wall[4][2][7].kolor);
		b4 = dajKolor(wall[0][0][4].kolor);
		b1 = dajKolor(wall[0][0][1].kolor);
		b7 = dajKolor(wall[0][0][7].kolor);
	}
	xfunkcja('x');
	sfunkcja('s');
	wfunkcja('w');
}
//////////
void zoltyKrzyz(Sciana sciana[6][3][9])
{
	int c1 = dajKolor(wall[5][0][1].kolor);
	int c3 = dajKolor(wall[5][0][3].kolor);
	int c7 = dajKolor(wall[5][0][7].kolor);
	int c5 = dajKolor(wall[5][0][5].kolor);
	// while((c1!=1)|(c3!=1)|(c7!=1)|(c5!=1))
	while (!((c1 == 1)&(c3 == 1)&(c7 == 1)&(c5 == 1)))
	{
		if ((c1 == 1)&(c7 == 1))
		{
			tfunkcja('t');

		}
		if (((c1 != 1)&(c3 != 1)&(c7 != 1)&(c5 != 1)) | ((c5 == 1)&(c3 == 1)))
		{
			zfunkcja('z');
			cfunkcja('c');
			tfunkcja('t');
			vfunkcja('v');
			yfunkcja('y');
			xfunkcja('x');
		}
		if ((c5 == 1)&(c7 == 1))
		{
			yfunkcja('y');
		}
		else if ((c3 == 1)&(c7 == 1))
		{
			tfunkcja('t');
			tfunkcja('t');
		}
		else if ((c3 == 1)&(c1 == 1))
		{
			tfunkcja('t');
		}
		if ((c5 == 1)&(c1 == 1))
		{
			zfunkcja('z');
			tfunkcja('t');
			cfunkcja('c');
			yfunkcja('y');
			vfunkcja('v');
			xfunkcja('x');
		}
		c1 = dajKolor(wall[5][0][1].kolor);
		c3 = dajKolor(wall[5][0][3].kolor);
		c7 = dajKolor(wall[5][0][7].kolor);
		c5 = dajKolor(wall[5][0][5].kolor);
	}
}

void permutacjaKrzyza(Sciana sciana[6][3][9])
{
	int g1 = dajKolor(wall[2][0][1].kolor);
	int z1 = dajKolor(wall[1][2][1].kolor);
	int n1 = dajKolor(wall[3][2][1].kolor);
	int b1 = dajKolor(wall[0][0][1].kolor);
	int g4 = dajKolor(wall[2][0][4].kolor);
	int z4 = dajKolor(wall[1][2][4].kolor);
	int n4 = dajKolor(wall[3][2][4].kolor);
	int b4 = dajKolor(wall[0][0][4].kolor);
	while ((g1 != g4) | (z1 != z4) | (n1 != n4) | (b1 != b4))
	{
		if ((g1 == g4)&(n1 == n4))
		{
			tfunkcja('t');
			gfunkcja('g');
			bfunkcja('b');
			g1 = dajKolor(wall[2][0][1].kolor);
			z1 = dajKolor(wall[1][2][1].kolor);
			n1 = dajKolor(wall[3][2][1].kolor);
			b1 = dajKolor(wall[0][0][1].kolor);
			g4 = dajKolor(wall[2][0][4].kolor);
			z4 = dajKolor(wall[1][2][4].kolor);
			n4 = dajKolor(wall[3][2][4].kolor);
			b4 = dajKolor(wall[0][0][4].kolor);
		}
		if ((z1 == z4)&(b1 == b4))
		{
			ffunkcja('f');
			ffunkcja('f');
			tfunkcja('t');
			ffunkcja('f');
			tfunkcja('t');
			tfunkcja('t');
			dfunkcja('d');
			tfunkcja('t');
			ffunkcja('f');
			ffunkcja('f');
			g1 = dajKolor(wall[2][0][1].kolor);
			z1 = dajKolor(wall[1][2][1].kolor);
			n1 = dajKolor(wall[3][2][1].kolor);
			b1 = dajKolor(wall[0][0][1].kolor);
			g4 = dajKolor(wall[2][0][4].kolor);
			z4 = dajKolor(wall[1][2][4].kolor);
			n4 = dajKolor(wall[3][2][4].kolor);
			b4 = dajKolor(wall[0][0][4].kolor);
		}
		if ((g1 == g4)&(b1 == b4))
		{
			yfunkcja('y');
			hfunkcja('h');
			nfunkcja('n');
		}
		else if ((n1 == n4)&(b1 == b4))
		{
			yfunkcja('y');
			hfunkcja('h');
			nfunkcja('n');
			yfunkcja('y');
			hfunkcja('h');
			nfunkcja('n');
		}
		else if ((n1 == n4)&(z1 == z4))
		{
			tfunkcja('t');
			gfunkcja('g');
			bfunkcja('b');
		}
		else if ((z1 == z4)&(g1 == g4))
		{
			ffunkcja('f');
			ffunkcja('f');
			tfunkcja('t');
			ffunkcja('f');
			tfunkcja('t');
			tfunkcja('t');
			dfunkcja('d');
			tfunkcja('t');
			ffunkcja('f');
			ffunkcja('f');
		}
		else
		{
			tfunkcja('t');
		}
		g1 = dajKolor(wall[2][0][1].kolor);
		z1 = dajKolor(wall[1][2][1].kolor);
		n1 = dajKolor(wall[3][2][1].kolor);
		b1 = dajKolor(wall[0][0][1].kolor);
		g4 = dajKolor(wall[2][0][4].kolor);
		z4 = dajKolor(wall[1][2][4].kolor);
		n4 = dajKolor(wall[3][2][4].kolor);
		b4 = dajKolor(wall[0][0][4].kolor);
	}
}
///////////
void permutacjaNaroznikow(Sciana sciana[6][3][9])
{
	int licznik = 0;
	int c2 = dajKolor(wall[5][0][2].kolor);
	int c6 = dajKolor(wall[5][0][6].kolor);
	int c8 = dajKolor(wall[5][0][8].kolor);
	int g0 = dajKolor(wall[2][0][0].kolor);
	int g1 = dajKolor(wall[2][0][1].kolor);
	int g2 = dajKolor(wall[2][0][2].kolor);
	int b2 = dajKolor(wall[0][0][2].kolor);
	int n0 = dajKolor(wall[3][2][0].kolor);
	int n1 = dajKolor(wall[3][2][1].kolor);
	int z0 = dajKolor(wall[1][2][0].kolor);
	int z1 = dajKolor(wall[1][2][1].kolor);
	int z2 = dajKolor(wall[1][2][2].kolor);
	while (!((((z0 == n1)&(c6 == z1)&(n0 == 1)) | ((z0 == z1)&(c6 == 1)&(n0 == n1)) | ((z0 == 1)&(c6 == n1)&(n0 == z1)))&
		(((z2 == g1)&(c8 == z1)&(g0 == 1)) | ((z2 == z1)&(c8 == 1)&(g0 == g1)) | ((z2 == 1)&(c8 == g1)&(g0 == z1)))))
	{
		while (!((((z0 == n1)&(c6 == z1)&(n0 == 1)) | ((z0 == z1)&(c6 == 1)&(n0 == n1)) | ((z0 == 1)&(c6 == n1)&(n0 == z1))) | (licznik == 4)))
		{
			tfunkcja('t');
			gfunkcja('g');
			bfunkcja('b');
			z0 = dajKolor(wall[1][2][0].kolor);
			c6 = dajKolor(wall[5][0][6].kolor);
			n0 = dajKolor(wall[3][2][0].kolor);
			n1 = dajKolor(wall[3][2][1].kolor);
			z1 = dajKolor(wall[1][2][1].kolor);
			licznik++;
			
		}
		b2 = dajKolor(wall[0][0][2].kolor);
		c2 = dajKolor(wall[5][0][2].kolor);
		g2 = dajKolor(wall[2][0][2].kolor);
		n1 = dajKolor(wall[3][2][1].kolor);
		z1 = dajKolor(wall[1][2][1].kolor);
		if ((licznik == 4) | ((b2 == n1) | (c2 == n1) | (g2 == n1)))
		{
			efunkcja('e');
			tfunkcja('t');
			cfunkcja('c');
			yfunkcja('y');
			rfunkcja('r');
			tfunkcja('t');
			vfunkcja('v');
			yfunkcja('y');
		}
		else
		{
			tfunkcja('t');
			gfunkcja('g');
			bfunkcja('b');
			cfunkcja('c');
			yfunkcja('y');
			efunkcja('e');
			tfunkcja('t');
			vfunkcja('v');
			yfunkcja('y');
			rfunkcja('r');
			tfunkcja('t');
		}
		//c0=dajKolor(wall[5][0][0].kolor);
		c2 = dajKolor(wall[5][0][2].kolor);
		c6 = dajKolor(wall[5][0][6].kolor);
		c8 = dajKolor(wall[5][0][8].kolor);
		g0 = dajKolor(wall[2][0][0].kolor);
		g1 = dajKolor(wall[2][0][1].kolor);
		g2 = dajKolor(wall[2][0][2].kolor);
		//b0=dajKolor(wall[0][0][0].kolor);
		//b1=dajKolor(wall[0][0][1].kolor);
		b2 = dajKolor(wall[0][0][2].kolor);
		n0 = dajKolor(wall[3][2][0].kolor);
		n1 = dajKolor(wall[3][2][1].kolor);
		//n2=dajKolor(wall[3][2][2].kolor);
		z0 = dajKolor(wall[1][2][0].kolor);
		z1 = dajKolor(wall[1][2][1].kolor);
		z2 = dajKolor(wall[1][2][2].kolor);
		licznik = 0;
		//if()
	}
}
void ostatniaPermutacja(Sciana sciana[6][3][9])
{
	int g0 = dajKolor(wall[2][0][0].kolor);
	int g1 = dajKolor(wall[2][0][1].kolor);
	int g2 = dajKolor(wall[2][0][2].kolor);
	int b0 = dajKolor(wall[0][0][0].kolor);
	int b1 = dajKolor(wall[0][0][1].kolor);
	int b2 = dajKolor(wall[0][0][2].kolor);
	int n0 = dajKolor(wall[3][2][0].kolor);
	int n1 = dajKolor(wall[3][2][1].kolor);
	int n2 = dajKolor(wall[3][2][2].kolor);
	int z0 = dajKolor(wall[1][2][0].kolor);
	int z1 = dajKolor(wall[1][2][1].kolor);
	int z2 = dajKolor(wall[1][2][2].kolor);
	while (!((z0 == z1)&(z2 == z1)&(g2 == g1)&(g0 == g1)&(b0 == b1)&(b2 == b1)&(n2 == n1)&(n0 == n1)))
	{
		if (((z0 == 1)&(z2 == 1)) | ((n0 == 1)&(z2 == 1)&(g2 == 1)) | ((z0 == 1)&(g0 == 1)&(b2 == 1)))
		{
			vfunkcja('v');
			nfunkcja('n');
			cfunkcja('c');
			zfunkcja('z');
			nfunkcja('n');
			xfunkcja('x');
			yfunkcja('y');
			zfunkcja('z');
			bfunkcja('b');
			xfunkcja('x');
			vfunkcja('v');
			bfunkcja('b');
			cfunkcja('c');
			tfunkcja('t');
		}
		else if ((n0 == 1)&(g0 == 1))
		{
			zfunkcja('z');
			bfunkcja('b');
			xfunkcja('x');
			vfunkcja('v');
			bfunkcja('b');
			cfunkcja('c');
			yfunkcja('y');
			vfunkcja('v');
			nfunkcja('n');
			cfunkcja('c');
			zfunkcja('z');
			nfunkcja('n');
			xfunkcja('x');
			tfunkcja('t');
		}
		else if ((n0 == 1)&(b2 == 1))
		{
			zfunkcja('z');
			bfunkcja('b');
			xfunkcja('x');
			vfunkcja('v');
			bfunkcja('b');
			cfunkcja('c');
			tfunkcja('t');
			tfunkcja('t');
			vfunkcja('v');
			nfunkcja('n');
			cfunkcja('c');
			zfunkcja('z');
			nfunkcja('n');
			xfunkcja('x');
			tfunkcja('t');
			tfunkcja('t');
		}
		else
		{
			tfunkcja('t');
			gfunkcja('g');
			bfunkcja('b');
		}
		g0 = dajKolor(wall[2][0][0].kolor);
		g1 = dajKolor(wall[2][0][1].kolor);
		g2 = dajKolor(wall[2][0][2].kolor);
		b0 = dajKolor(wall[0][0][0].kolor);
		b1 = dajKolor(wall[0][0][1].kolor);
		b2 = dajKolor(wall[0][0][2].kolor);
		n0 = dajKolor(wall[3][2][0].kolor);
		n1 = dajKolor(wall[3][2][1].kolor);
		n2 = dajKolor(wall[3][2][2].kolor);
		z0 = dajKolor(wall[1][2][0].kolor);
		z1 = dajKolor(wall[1][2][1].kolor);
		z2 = dajKolor(wall[1][2][2].kolor);
	}
	while (!(dajKolor(wall[1][2][1].kolor) == dajKolor(wall[1][2][4].kolor)))
		tfunkcja('t');

}
void Keyboard(unsigned char key, int x, int y)
{


	if (key == 'o')
	{
		int los, licznik;
		slip = 0;
		for (licznik = 0; licznik < 25; licznik++)
		{
			los = (rand() % 18);
			switch (los)
			{
			case 0:
			{
				qfunkcja('q');
				break;
			}
			case 1:
			{
				wfunkcja('w');
				break;
			}
			case 2:
			{
				sfunkcja('s');
				break;
			}
			case 3:
			{
				afunkcja('a');
				break;
			}
			case 4:
			{
				zfunkcja('z');
				break;
			}
			case 5:
			{
				xfunkcja('x');
				break;
			}
			case 6:
			{
				rfunkcja('r');
				break;
			}
			case 7:
			{
				efunkcja('e');
				break;
			}
			case 8:
			{
				ffunkcja('f');
				break;
			}
			case 9:
			{
				dfunkcja('d');
				break;
			}
			case 10:
			{
				vfunkcja('v');
				break;
			}
			case 11:
			{
				cfunkcja('c');
				break;
			}
			case 12:
			{
				tfunkcja('t');
				break;
			}
			case 13:

			{
				yfunkcja('y');
				break;
			}
			case 14:
			{
				gfunkcja('g');
				break;
			}
			case 15:
			{
				hfunkcja('h');
				break;
			}
			case 16:
			{
				bfunkcja('b');
				break;
			}
			case 17:
			{
				nfunkcja('n');
				break;
			}
			}
			transformacja(ref);
		}
		slip = 12;
	}
	if (key == 'm')
	{
		slip = 3;
		szukajBialej(wall);
		while ((dajKolor(wall[5][0][1].kolor) != 0) |
			(dajKolor(wall[5][0][3].kolor) != 0) |
			(dajKolor(wall[5][0][5].kolor) != 0) |
			(dajKolor(wall[5][0][7].kolor) != 0))
			szukajBialej2(wall);
		bialyKrzyz(wall);
		naroznikiBialej(wall);
		drugaWarstwa2(wall);
		zoltyKrzyz(wall);
		permutacjaKrzyza(wall);
		permutacjaNaroznikow(wall);
		ostatniaPermutacja(wall);
		slip = 12;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		{

			rotatex = floor(rotatex);
			rotatey = floor(rotatey);
			if ((rotatex>0)&(rotatey>0))
			{
				while ((rotatex != 0) | (rotatey != 0))
				{
					if (rotatex != 0)
						rotatex -= 1;
					if (rotatey != 0)
						rotatey -= 1;
					Sleep(5);
					Display();
				}
			}
			if ((rotatex<0)&(rotatey>0))
			{
				while ((rotatex != 0) | (rotatey != 0))
				{
					if (rotatex != 0)
						rotatex += 1;
					if (rotatey != 0)
						rotatey -= 1;
					Sleep(5);
					Display();
				}
			}
			if ((rotatex<0)&(rotatey<0))
			{
				while ((rotatex != 0) | (rotatey != 0))
				{
					if (rotatex != 0)
						rotatex += 1;
					if (rotatey != 0)
						rotatey += 1;
					Sleep(5);
					Display();
				}
			}
			if ((rotatex>0)&(rotatey<0))
			{
				while ((rotatex != 0) | (rotatey != 0))
				{
					if (rotatex != 0)
						rotatex -= 1;
					if (rotatey != 0)
						rotatey += 1;
					Sleep(5);
					Display();
				}
			}
			gratulacje = 1;
			while ((graty1>8) | (graty2>-8))
			{
				graty1 -= 0.02;
				graty2 -= 0.02;
				Display();
			}
			Display();
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
	if (key == '1')
	{
		slip = 0;
		szukajBialej(wall);
		while ((dajKolor(wall[5][0][1].kolor) != 0) |
			(dajKolor(wall[5][0][3].kolor) != 0) |
			(dajKolor(wall[5][0][5].kolor) != 0) |
			(dajKolor(wall[5][0][7].kolor) != 0))
			szukajBialej2(wall);
		slip = 12;
	}
	if (key == '2')
	{
		slip = 0;
		bialyKrzyz(wall);
		slip = 12;
	}
	if (key == '3')
	{
		slip = 0;
		naroznikiBialej(wall);
		slip = 12;
	}
	if (key == '4')
	{
		slip = 0;
		drugaWarstwa2(wall);
		slip = 12;
	}
	if (key == '5')
	{
		slip = 6;
		zoltyKrzyz(wall);
		slip = 12;
	}
	if (key == '6')
	{
		slip = 6;
		permutacjaKrzyza(wall);
		slip = 12;
	}
	if (key == '7')
	{
		slip = 6;
		permutacjaNaroznikow(wall);
		slip = 12;
	}
	if (key == '8')
	{
		slip = 6;
		ostatniaPermutacja(wall);
		slip = 12;
	}
	if (key == 'q')
		qfunkcja(key);
	if (key == 'w')
		wfunkcja(key);
	///
	if (key == 's')
		sfunkcja(key);
	///
	if (key == 27)
	{
		menu = 0;
		gratulacje = 0;
		GLfloat graty1 = 24;
		GLfloat graty2 = 8;
		Display();
	}
	if (key == 'a')
		afunkcja(key);
	///
	if (key == 'z')
		zfunkcja(key);
	if (key == 'x')
		xfunkcja(key);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (key == 'r')
		rfunkcja(key);

	if (key == 'e')
		efunkcja(key);
	///
	if (key == 'f')
		ffunkcja(key);
	///
	if (key == 'd')
		dfunkcja(key);
	///

	if (key == 'v')
		vfunkcja(key);
	if (key == 'c')
		cfunkcja(key);
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (key == 't')
		tfunkcja(key);
	////
	if (key == 'y')
		yfunkcja(key);
	////
	if (key == 'g')
		gfunkcja(key);
	////
	if (key == 'h')
		hfunkcja(key);
	////
	if (key == 'b')
		bfunkcja(key);
	////
	if (key == 'n')
		nfunkcja(key);
	if (key == '+'){
		Density += 0.002;
		Display();
	}
	if (key == '-'){
		Density -= 0.002;
		Display();

	}
}

void SpecialKeys(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_LEFT:
		rotatey -= 2;
		break;

	case GLUT_KEY_UP:
		rotatex -= 2;
		break;

	case GLUT_KEY_RIGHT:
		rotatey += 2;
		break;

	case GLUT_KEY_DOWN:
		rotatex += 2;
		break;

	case GLUT_KEY_F2:
		rotatez += 2;
		break;

	case GLUT_KEY_F3:
		rotatez -= 2;
		break;
	}

	Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
}

// obs3uga przycisków myszki

void MouseButton(int button, int state, int x, int y)
{
	if ((button == GLUT_LEFT_BUTTON)&(x > przycisk1x)&(x<przycisk1x + szer)&(y>przycisk1y)&(y < przycisk1y + wys))
	{
		if ((state == GLUT_UP)&&(akt1 == 1)&&(menu == 0))
		{
			button = 10;
			menu = 1;
			//printf("menu opcje dzwiek");
		}
		if ((state == GLUT_UP)&&(menu == 2)){
			button = 10;
			
			menu = 3;	
		}
		if ((state == GLUT_UP)&&(menu == 3))
		{
			button = 10;
			menu_dzwieki = 0;
			Display();
		}
		if ((state == GLUT_UP)&&(menu == 4))
		{
			button = 10;
			menu_latwy = 0;
			Display();
		}
		Display();
	}
	else if ((button == GLUT_LEFT_BUTTON)&(x > przycisk3x)&(x<przycisk3x + szer)&(y>przycisk3y)&(y < przycisk3y + wys))
	{
		if ((state == GLUT_UP)&&(menu == 0))
			exit(0);
		if ((state == GLUT_UP)&&(menu == 2)){
			button = 10;
			menu = 0;
		}
		if ((state == GLUT_UP)&&(menu == 3)){
			button = 10;
			menu = 2;
		}
		if ((state == GLUT_UP)&&(menu == 4)){
			button = 10;
			menu = 2;
		}
	}
	else if ((button == GLUT_LEFT_BUTTON)&(x > przycisk2x)&(x<przycisk2x + szer)&(y>przycisk2y)&(y < przycisk2y + wys))
	{
		if ((state == GLUT_UP)&&(menu == 0))
		{
			button = 10;
			state = GLUT_DOWN;
			menu = 2;
			Display();
		}
		if ((state == GLUT_UP)&&(menu == 2))
		{
			button = 10;
			menu = 4;
			Display();
		}
		if ((state == GLUT_UP)&&(menu == 3))
		{
			button = 10;
			menu_dzwieki = 1;
			Display();
		}
		if ((state == GLUT_UP)&&(menu == 4))
		{
			button = 10;
			menu_latwy = 1;
			Display();
		}
	}

	if (button == GLUT_LEFT_BUTTON)
	{
		// zapamietanie stanu lewego przycisku myszki
		button_state = state;
		// zapamietanie po3o?enia kursora myszki
		if (state == GLUT_DOWN)
		{
			button_x = x;
			button_y = y;
		}
	}
}

// obs3uga ruchu kursora myszki

void MouseMotion(int x, int y)
{
	if ((button_state == GLUT_DOWN)&((menu != 0)&(gratulacje != 1)))
	{
		rotatey += 10 * (right - left) / glutGet(GLUT_WINDOW_WIDTH) *(x - button_x);
		button_x = x;
		rotatex -= 10 * (top - bottom) / glutGet(GLUT_WINDOW_HEIGHT) *(button_y - y);
		button_y = y;
		glutPostRedisplay();
	}
}

void MousePassiveMotion(int x, int y)
{

	if ((x > przycisk1x)&(x<przycisk1x + szer)&(y>przycisk1y)&(y < przycisk1y + wys))
	{
		akt1 = 1;
		akt4 = 1;
		akt7 = 1;
		akt10 = 1;
		Display();
	}
	else if (akt1 == 1)
	{
		akt1 = 0;
		akt4 = 0;
		akt7 = 0;
		akt10 = 0;
		Display();
	}
	else if ((x > przycisk2x)&(x<przycisk2x + szer)&(y>przycisk2y)&(y < przycisk2y + wys))
	{
		akt2 = 1;
		akt5 = 1;
		akt8 = 1;
		akt11 = 1;
		Display();
	}
	else if (akt2 == 1)
	{
		akt2 = 0;
		akt5 = 0;
		akt8 = 0;
		akt11 = 0;
		Display();
	}
	else if ((x > przycisk3x)&(x<przycisk3x + szer)&(y>przycisk3y)&(y < przycisk3y + wys))
	{
		akt3 = 1;
		akt6 = 1;
		akt9 = 1;
		akt12 = 1;
		Display();
	}
	else if (akt3 == 1)
	{
		akt3 = 0;
		akt6 = 0;
		akt9 = 0;
		akt12 = 0;
		Display();
	}
}

void Menu(int value)
{
	switch (value)
	{
	case FULL_WINDOW:
		aspect = FULL_WINDOW;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

	case ASPECT_1_1:
		aspect = ASPECT_1_1;
		Reshape(glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));
		break;

	case EXIT:
		exit(0);
	}
}

int main(int argc, char * argv[])
{
	menu = 0;
	akt1 = 0;
	akt2 = 0;
	akt3 = 0;
	int j, k;
	srand(time(0));

	for (j = 0; j < 6; j++)
		for (k = 0; k < 9; k++)
			kolor_zew[j][k] = j;
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(600, 600);
	inicjujWspolrzedne();
	inicjujKolory(wall, kolor_zew);

	glutCreateWindow("Kostka Rubika");

	glGenTextures(1, &tekstura[0]);
	glBindTexture(GL_TEXTURE_2D, tekstura[0]);
	LoadTGATexture("menu.tga");
	glGenTextures(1, &tekstura[1]);
	glBindTexture(GL_TEXTURE_2D, tekstura[1]);
	LoadTGATexture("start.tga");
	glGenTextures(1, &tekstura[2]);
	glBindTexture(GL_TEXTURE_2D, tekstura[2]);
	LoadTGATexture("opcje.tga");
	glGenTextures(1, &tekstura[3]);
	glBindTexture(GL_TEXTURE_2D, tekstura[3]);
	LoadTGATexture("wyjscie.tga");
	glGenTextures(1, &tekstura[4]);
	glBindTexture(GL_TEXTURE_2D, tekstura[4]);
	LoadTGATexture("start_on.tga");
	glGenTextures(1, &tekstura[5]);
	glBindTexture(GL_TEXTURE_2D, tekstura[5]);
	LoadTGATexture("opcje_on.tga");
	glGenTextures(1, &tekstura[6]);
	glBindTexture(GL_TEXTURE_2D, tekstura[6]);
	LoadTGATexture("wyjscie_on.tga");
	glGenTextures(1, &tekstura[7]);
	glBindTexture(GL_TEXTURE_2D, tekstura[7]);
	LoadTGATexture("opcje_menu.tga");
	glGenTextures(1, &tekstura[8]);
	glBindTexture(GL_TEXTURE_2D, tekstura[8]);
	LoadTGATexture("dzwiek.tga");
	glGenTextures(1, &tekstura[9]);
	glBindTexture(GL_TEXTURE_2D, tekstura[9]);
	LoadTGATexture("dzwiek_on.tga");
	glGenTextures(1, &tekstura[10]);
	glBindTexture(GL_TEXTURE_2D, tekstura[10]);
	LoadTGATexture("poziom.tga");
	glGenTextures(1, &tekstura[11]);
	glBindTexture(GL_TEXTURE_2D, tekstura[11]);
	LoadTGATexture("poziom_on.tga");
	glGenTextures(1, &tekstura[12]);
	glBindTexture(GL_TEXTURE_2D, tekstura[12]);
	LoadTGATexture("powrot.tga");
	glGenTextures(1, &tekstura[13]);
	glBindTexture(GL_TEXTURE_2D, tekstura[13]);
	LoadTGATexture("powrot_on.tga");
	glGenTextures(1, &tekstura[14]);
	glBindTexture(GL_TEXTURE_2D, tekstura[14]);
	LoadTGATexture("dzwiek_menu.tga");
	glGenTextures(1, &tekstura[15]);
	glBindTexture(GL_TEXTURE_2D, tekstura[15]);
	LoadTGATexture("poziom_menu.tga");
	glGenTextures(1, &tekstura[16]);
	glBindTexture(GL_TEXTURE_2D, tekstura[16]);
	LoadTGATexture("wlaczone.tga");
	glGenTextures(1, &tekstura[17]);
	glBindTexture(GL_TEXTURE_2D, tekstura[17]);
	LoadTGATexture("wlaczone_on.tga");
	glGenTextures(1, &tekstura[18]);
	glBindTexture(GL_TEXTURE_2D, tekstura[18]);
	LoadTGATexture("wylaczone.tga");
	glGenTextures(1, &tekstura[19]);
	glBindTexture(GL_TEXTURE_2D, tekstura[19]);
	LoadTGATexture("wylaczone_on.tga");
	glGenTextures(1, &tekstura[20]);
	glBindTexture(GL_TEXTURE_2D, tekstura[20]);
	LoadTGATexture("latwy.tga");
	glGenTextures(1, &tekstura[21]);
	glBindTexture(GL_TEXTURE_2D, tekstura[21]);
	LoadTGATexture("latwy_on.tga");
	glGenTextures(1, &tekstura[22]);
	glBindTexture(GL_TEXTURE_2D, tekstura[22]);
	LoadTGATexture("trudny.tga");
	glGenTextures(1, &tekstura[23]);
	glBindTexture(GL_TEXTURE_2D, tekstura[23]);
	LoadTGATexture("trudny_on.tga");
	glGenTextures(1, &tekstura[24]);
	glBindTexture(GL_TEXTURE_2D, tekstura[24]);
	LoadTGATexture("gratulacje.tga");

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutKeyboardFunc(Keyboard);
	glutSpecialFunc(SpecialKeys);

	// obs3uga przycisków myszki
	glutMouseFunc(MouseButton);

	// obs3uga ruchu kursora myszki
	glutMotionFunc(MouseMotion);

	// obs3uga ruchu kursora myszki
	glutPassiveMotionFunc(MousePassiveMotion);

	glutCreateMenu(Menu);

	int MenuAspect = glutCreateMenu(Menu);

#ifdef WIN32
	glutAddMenuEntry("Aspekt obrazu - całe okno", FULL_WINDOW);
#else
	glutAddMenuEntry("Aspekt obrazu - cale okno", FULL_WINDOW);
#endif

	glutAddMenuEntry("Aspekt obrazu 1:1", ASPECT_1_1);
	glutCreateMenu(Menu);
	glutAddSubMenu("Aspekt obrazu", MenuAspect);

#ifdef WIN32
	glutAddMenuEntry("Wyjście", EXIT);
#else
	glutAddMenuEntry("Wyjscie", EXIT);
#endif

	glutAttachMenu(GLUT_RIGHT_BUTTON);
	init();
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	glutMainLoop();
	glDeleteTextures(24, tekstura);
	return 0;
}
