#pragma once
#include "stdlib.h"
#include "assert.h"
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

#define LOG_OUT(_x_) OutputDebugString(_x_) 
#define LOG_OUT_W(_x_)  OutputDebugStringW(_x_) 
#define LOG_OUT_A(_x_)  OutputDebugStringA(_x_) 


// ���� ������� ���� ������ �Լ���

// ���� /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool LoadBmp(const char* filename, byte** pImage, int& height, int& width);
bool SaveBmp(const char* filename, byte* pImage, int height, int width);
bool convert1Dto2D(byte* src, double** dst_Y, double** dst_U, double** dst_V, int height, int width);
bool convert2Dto1D(double** src_Y, double** src_U, double** src_V, byte* dst, int height, int width);

void convert2Dto3D(double **src2D, double ***dst3D, int height, int width);
void convert3Dto2D(double ***src3D, double **dst2D, int height, int width);

double *dmatrix1D(int nH); //1���� vector �Ҵ�
double **dmatrix2D(int nH, int nW); //2���� matrix �Ҵ�
double ***dmatrix3D(int nH, int nW, int nC);//3���� tensor �Ҵ�
double ****dmatrix4D(int nH, int nW, int nC, int nNum); //4���� tensor �Ҵ�

void free_dmatrix1D(double *Image, int nH); //1���� vector �Ҵ� ����
void free_dmatrix2D(double **Image, int nH, int nW); //2���� matrix �Ҵ� ����
void free_dmatrix3D(double ***Image, int nH, int nW, int nC); //3���� tensor �Ҵ� ����
void free_dmatrix4D(double ****Image, int nH, int nW, int nC, int nNum); //4���� tensor �Ҵ� ����

double clip(double x, double minVal, double maxVal);
double** simpleUpsampling2x(double **Image, int nH, int nW);



// ���� /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool LoadBmp(const char* filename, byte** pImage, int& height, int& width)
{
	FILE* fp;

	// ��Ʈ�� ���� ����ü
	BITMAPFILEHEADER BMFH;					///< BitMap File Header.
	BITMAPINFOHEADER BMIH;					///< BitMap Info Header.

	fopen_s(&fp, filename, "rb");
	if (nullptr == fp)
	{
		LOG_OUT_A("fopen() error");
		return false;
	}

	// ������ ũ�⸸ŭ ���Ͽ��� �о��, �׸��� ��Ʈ����������� �־���
	fread(&BMFH, sizeof(BITMAPFILEHEADER), 1, fp);
	if (BMFH.bfType != 0x4d42)	// ��Ʈ�� ������ �ƴϸ� �����Ѵ�.
	{
		fclose(fp);
		LOG_OUT_A("not '.bmp' file !!!");
		return false;
	}

	fread(&BMIH, sizeof(BITMAPINFOHEADER), 1, fp);	//��������� �ִ� ũ���� ������ŭ �о
	if (BMIH.biBitCount != 24 || BMIH.biCompression != BI_RGB) //24��Ʈ���� üũ�ϰ�, ������ �ȵǾ� �ִ��� üũ�� ��
	{
		fclose(fp);
		return false;
	}

	INT Width = BMIH.biWidth;
	INT Height = BMIH.biHeight - 1;
	INT BytePerScanline = (Width * 3 + 3) & ~3;  // �е�
	INT size = BMFH.bfSize;
	height = BMIH.biHeight;
	width = BMIH.biWidth;

	*pImage = (BYTE*)malloc(size);

	fread(*pImage, size, 1, fp);  // ������ ������ ���� �о�´�.
								  //*pImage += BytePerScanline * Height;

								  // FILE*�� ����.
	fclose(fp);

	return true;
}
bool SaveBmp(const char* filename, byte* pImage, int height, int width)
{
	// DIB�� ������ �����Ѵ�.
	BITMAPINFO dib_define;
	dib_define.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	dib_define.bmiHeader.biWidth = width;
	dib_define.bmiHeader.biHeight = height;
	dib_define.bmiHeader.biPlanes = 1;
	dib_define.bmiHeader.biBitCount = 24;
	dib_define.bmiHeader.biCompression = BI_RGB;
	dib_define.bmiHeader.biSizeImage = (((width * 24 + 31) & ~31) >> 3) * height;
	dib_define.bmiHeader.biXPelsPerMeter = 0;
	dib_define.bmiHeader.biYPelsPerMeter = 0;
	dib_define.bmiHeader.biClrImportant = 0;
	dib_define.bmiHeader.biClrUsed = 0;

	// DIB ������ ��� ������ �����Ѵ�.
	BITMAPFILEHEADER dib_format_layout;
	ZeroMemory(&dib_format_layout, sizeof(BITMAPFILEHEADER));
	dib_format_layout.bfType = *(WORD*)"BM";
	dib_format_layout.bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);// +dib_define.bmiHeader.biSizeImage;
	dib_format_layout.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

	// ���� ����.
	FILE* fp = nullptr;
	fopen_s(&fp, filename, "wb");
	if (nullptr == fp)
	{
		LOG_OUT_A("fopen() error");
		return false;
	}

	// ���� �� ��� �� ������ ����.
	fwrite(&dib_format_layout, 1, sizeof(BITMAPFILEHEADER), fp);
	fwrite(&dib_define, 1, sizeof(BITMAPINFOHEADER), fp);
	fwrite(pImage, 1, dib_define.bmiHeader.biSizeImage, fp);
	fclose(fp);

	return true;
}
bool convert1Dto2D(byte* src, double** dst_Y, double** dst_U, double** dst_V, int height, int width) {
	int iR, iG, iB;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			iB = src[3 * width*y + 3 * x + 0];
			iG = src[3 * width*y + 3 * x + 1];
			iR = src[3 * width*y + 3 * x + 2];

			dst_Y[y][x] = iR*0.299 + iG*0.587 + iB*0.114;
			dst_U[y][x] = (iB - dst_Y[y][x])*0.565;
			dst_V[y][x] = (iR - dst_Y[y][x])*0.713;

			dst_Y[y][x] = dst_Y[y][x] / 255.0; // in the range from [0, 255] to [0, 1] 
		}
	}
	return true;
}

bool convert2Dto1D(double** src_Y, double** src_U, double** src_V, byte* dst, int height, int width) {
	int iCount = 0;
	int iR, iG, iB;
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			src_Y[y][x] = src_Y[y][x] * 255.0; // in the range from [0, 1] to [0, 255] 
			iR = byte(clip(src_Y[y][x] + 1.403*src_V[y][x], 0, 255));
			iG = byte(clip(src_Y[y][x] - 0.344*src_U[y][x] - 0.714*src_V[y][x], 0, 255));
			iB = byte(clip(src_Y[y][x] + 1.770*src_U[y][x], 0, 255));

			dst[iCount + 0] = iB;
			dst[iCount + 1] = iG;
			dst[iCount + 2] = iR;
			iCount = iCount + 3;
		}
	}


	return true;
}

double clip(double x, double minVal, double maxVal) {
	if (x < minVal) x = minVal;
	if (x > maxVal) x = maxVal;

	return x;

}

double** simpleUpsampling2x(double **Image, int nH, int nW) {
	double** outImg = dmatrix2D(nH * 2, nW * 2);

	for (int y = 0; y < nH; y++) {
		for (int x = 0; x < nW; x++) {
			outImg[2 * y + 0][2 * x + 0] = Image[y][x];
			outImg[2 * y + 0][2 * x + 1] = Image[y][x];
			outImg[2 * y + 1][2 * x + 0] = Image[y][x];
			outImg[2 * y + 1][2 * x + 1] = Image[y][x];
		}
	}
	return outImg;
}

double *dmatrix1D(int nH) {
	double *tmp = new double[nH];
	return tmp;
}

double **dmatrix2D(int nH, int nW) {
	double **Temp;

	Temp = new double*[nH];
	for (int y = 0; y < nH; y++)
		Temp[y] = new double[nW];

	for (int y = 0; y < nH; y++) {
		for (int x = 0; x < nW; x++) {
			Temp[y][x] = 0;
		}
	}

	return Temp;
}

double ***dmatrix3D(int nH, int nW, int nC) {
	double ***Temp;

	Temp = new double**[nH];
	for (int y = 0; y < nH; y++)
		Temp[y] = new double*[nW];

	for (int y = 0; y < nH; y++) {
		for (int x = 0; x < nW; x++) {
			Temp[y][x] = new double[nC];
		}
	}

	for (int y = 0; y < nH; y++) {
		for (int x = 0; x < nW; x++) {
			for (int c = 0; c < nC; c++) {
				Temp[y][x][c] = 0;
			}
		}
	}

	return Temp;
}

double ****dmatrix4D(int nH, int nW, int nC, int nNum) {
	double ****Temp;

	Temp = new double***[nH];
	for (int y = 0; y < nH; y++)
		Temp[y] = new double**[nW];

	for (int y = 0; y < nH; y++) {
		for (int x = 0; x < nW; x++) {
			Temp[y][x] = new double*[nC];
		}
	}

	for (int y = 0; y < nH; y++) {
		for (int x = 0; x < nW; x++) {
			for (int c = 0; c < nC; c++) {
				Temp[y][x][c] = new double[nNum];
			}
		}
	}

	for (int y = 0; y < nH; y++) {
		for (int x = 0; x < nW; x++) {
			for (int c = 0; c < nC; c++) {
				for (int n = 0; n < nNum; n++)
					Temp[y][x][c][n] = 0;
			}
		}
	}

	return Temp;
}

void free_dmatrix1D(double *Image, int nH) {
	delete[] Image;

}

void free_dmatrix2D(double **Image, int nH, int nW) {
	for (int y = 0; y < nH; y++)
		delete[] Image[y];

	delete[] Image;
}

void free_dmatrix3D(double ***Image, int nH, int nW, int nC) {
	for (int y = 0; y < nH; y++)
		for (int x = 0; x < nW; x++) {
			delete[] Image[y][x];
		}

	for (int y = 0; y < nH; y++)
		delete[] Image[y];

	delete[] Image;
}

void free_dmatrix4D(double ****Image, int nH, int nW, int nC, int nNum) {
	for (int y = 0; y < nH; y++)
		for (int x = 0; x < nW; x++) {
			for (int c = 0; c < nC; c++) {
				delete[] Image[y][x][c];
			}
		}
	for (int y = 0; y < nH; y++)
		for (int x = 0; x < nW; x++) {
			delete[] Image[y][x];
		}

	for (int y = 0; y < nH; y++)
		delete[] Image[y];

	delete[] Image;
}


void convert2Dto3D(double **src2D, double ***dst3D, int height, int width) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			dst3D[y][x][0] = src2D[y][x];
		}
	}
}

void convert3Dto2D(double ***src3D, double **dst2D, int height, int width) {
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			dst2D[y][x] = src3D[y][x][0];
		}
	}
}