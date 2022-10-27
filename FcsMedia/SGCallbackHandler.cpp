

#include "stdafx.h"
#include "FcsMedia.h"
#include "SGCallbackHandler.h"
#include "ExportManager.h"
#include "FcsGrabber.h"
#include "keyFrameDll.h"
#include "FcsPlayer.h"
#include "JbuCapturer.h"

int YUV2RGB(void* pYUV, void* pRGB, int width, int height, bool alphaYUV, bool alphaRGB)
{
	if (NULL == pYUV)
	{
		return -1;
	}
	unsigned char* pYUVData = (unsigned char *)pYUV;
	unsigned char* pRGBData = (unsigned char *)pRGB;
	if (NULL == pRGBData)
	{
		if (alphaRGB)
		{
			pRGBData = new unsigned char[width*height * 4];
		}
		else
			pRGBData = new unsigned char[width*height * 3];
	}
	int Y1, U1, V1, Y2, alpha1, alpha2, R1, G1, B1, R2, G2, B2;
	int C1, D1, E1, C2;
	if (alphaRGB)
	{
		if (alphaYUV)
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					Y1 = *(pYUVData + i*width * 3 + j * 6);
					U1 = *(pYUVData + i*width * 3 + j * 6 + 1);
					Y2 = *(pYUVData + i*width * 3 + j * 6 + 2);
					V1 = *(pYUVData + i*width * 3 + j * 6 + 3);
					alpha1 = *(pYUVData + i*width * 3 + j * 6 + 4);
					alpha2 = *(pYUVData + i*width * 3 + j * 6 + 5);
					C1 = Y1 - 16;
					C2 = Y2 - 16;
					D1 = U1 - 128;
					E1 = V1 - 128;
					R1 = ((298 * C1 + 409 * E1 + 128) >> 8 > 255 ? 255 : (298 * C1 + 409 * E1 + 128) >> 8);
					G1 = ((298 * C1 - 100 * D1 - 208 * E1 + 128) >> 8 > 255 ? 255 : (298 * C1 - 100 * D1 - 208 * E1 + 128) >> 8);
					B1 = ((298 * C1 + 516 * D1 + 128) >> 8 > 255 ? 255 : (298 * C1 + 516 * D1 + 128) >> 8);
					R2 = ((298 * C2 + 409 * E1 + 128) >> 8 > 255 ? 255 : (298 * C2 + 409 * E1 + 128) >> 8);
					G2 = ((298 * C2 - 100 * D1 - 208 * E1 + 128) >> 8 > 255 ? 255 : (298 * C2 - 100 * D1 - 208 * E1 + 128) >> 8);
					B2 = ((298 * C2 + 516 * D1 + 128) >> 8 > 255 ? 255 : (298 * C2 + 516 * D1 + 128) >> 8);
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 2) = R1 < 0 ? 0 : R1;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 1) = G1 < 0 ? 0 : G1;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8) = B1 < 0 ? 0 : B1;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 3) = alpha1;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 6) = R2 < 0 ? 0 : R2;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 5) = G2 < 0 ? 0 : G2;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 4) = B2 < 0 ? 0 : B2;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 7) = alpha2;
				}
			}
		}
		else
		{
			int alpha = 255;
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					Y1 = *(pYUVData + i*width * 2 + j * 4);
					U1 = *(pYUVData + i*width * 2 + j * 4 + 1);
					Y2 = *(pYUVData + i*width * 2 + j * 4 + 2);
					V1 = *(pYUVData + i*width * 2 + j * 4 + 3);
					C1 = Y1 - 16;
					C2 = Y2 - 16;
					D1 = U1 - 128;
					E1 = V1 - 128;
					R1 = ((298 * C1 + 409 * E1 + 128) >> 8 > 255 ? 255 : (298 * C1 + 409 * E1 + 128) >> 8);
					G1 = ((298 * C1 - 100 * D1 - 208 * E1 + 128) >> 8 > 255 ? 255 : (298 * C1 - 100 * D1 - 208 * E1 + 128) >> 8);
					B1 = ((298 * C1 + 516 * D1 + 128) >> 8 > 255 ? 255 : (298 * C1 + 516 * D1 + 128) >> 8);
					R2 = ((298 * C2 + 409 * E1 + 128) >> 8 > 255 ? 255 : (298 * C2 + 409 * E1 + 128) >> 8);
					G2 = ((298 * C2 - 100 * D1 - 208 * E1 + 128) >> 8 > 255 ? 255 : (298 * C2 - 100 * D1 - 208 * E1 + 128) >> 8);
					B2 = ((298 * C2 + 516 * D1 + 128) >> 8 > 255 ? 255 : (298 * C2 + 516 * D1 + 128) >> 8);
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 2) = R1 < 0 ? 0 : R1;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 1) = G1 < 0 ? 0 : G1;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8) = B1 < 0 ? 0 : B1;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 3) = alpha;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 6) = R2 < 0 ? 0 : R2;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 5) = G2 < 0 ? 0 : G2;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 4) = B2 < 0 ? 0 : B2;
					*(pRGBData + (height - i - 1)*width * 4 + j * 8 + 7) = alpha;
				}
			}
		}
	}
	else
	{
		if (alphaYUV)
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					Y1 = *(pYUVData + i*width * 3 + j * 4);
					U1 = *(pYUVData + i*width * 3 + j * 4 + 1);
					Y2 = *(pYUVData + i*width * 3 + j * 4 + 2);
					V1 = *(pYUVData + i*width * 3 + j * 4 + 3);
					C1 = Y1 - 16;
					C2 = Y2 - 16;
					D1 = U1 - 128;
					E1 = V1 - 128;
					R1 = ((298 * C1 + 409 * E1 + 128) >> 8 > 255 ? 255 : (298 * C1 + 409 * E1 + 128) >> 8);
					G1 = ((298 * C1 - 100 * D1 - 208 * E1 + 128) >> 8 > 255 ? 255 : (298 * C1 - 100 * D1 - 208 * E1 + 128) >> 8);
					B1 = ((298 * C1 + 516 * D1 + 128) >> 8 > 255 ? 255 : (298 * C1 + 516 * D1 + 128) >> 8);
					R2 = ((298 * C2 + 409 * E1 + 128) >> 8 > 255 ? 255 : (298 * C2 + 409 * E1 + 128) >> 8);
					G2 = ((298 * C2 - 100 * D1 - 208 * E1 + 128) >> 8 > 255 ? 255 : (298 * C2 - 100 * D1 - 208 * E1 + 128) >> 8);
					B2 = ((298 * C2 + 516 * D1 + 128) >> 8 > 255 ? 255 : (298 * C2 + 516 * D1 + 128) >> 8);
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 2) = R1 < 0 ? 0 : R1;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 1) = G1 < 0 ? 0 : G1;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6) = B1 < 0 ? 0 : B1;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 5) = R2 < 0 ? 0 : R2;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 4) = G2 < 0 ? 0 : G2;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 3) = B2 < 0 ? 0 : B2;
				}
			}
		}
		else
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					Y1 = *(pYUVData + i*width * 2 + j * 4);
					U1 = *(pYUVData + i*width * 2 + j * 4 + 1);
					Y2 = *(pYUVData + i*width * 2 + j * 4 + 2);
					V1 = *(pYUVData + i*width * 2 + j * 4 + 3);
					C1 = Y1 - 16;
					C2 = Y2 - 16;
					D1 = U1 - 128;
					E1 = V1 - 128;
					R1 = ((298 * C1 + 409 * E1 + 128) >> 8 > 255 ? 255 : (298 * C1 + 409 * E1 + 128) >> 8);
					G1 = ((298 * C1 - 100 * D1 - 208 * E1 + 128) >> 8 > 255 ? 255 : (298 * C1 - 100 * D1 - 208 * E1 + 128) >> 8);
					B1 = ((298 * C1 + 516 * D1 + 128) >> 8>255 ? 255 : (298 * C1 + 516 * D1 + 128) >> 8);
					R2 = ((298 * C2 + 409 * E1 + 128) >> 8 > 255 ? 255 : (298 * C2 + 409 * E1 + 128) >> 8);
					G2 = ((298 * C2 - 100 * D1 - 208 * E1 + 128) >> 8 > 255 ? 255 : (298 * C2 - 100 * D1 - 208 * E1 + 128) >> 8);
					B2 = ((298 * C2 + 516 * D1 + 128) >> 8 > 255 ? 255 : (298 * C2 + 516 * D1 + 128) >> 8);
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 2) = R1 < 0 ? 0 : R1;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 1) = G1 < 0 ? 0 : G1;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6) = B1 < 0 ? 0 : B1;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 5) = R2 < 0 ? 0 : R2;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 4) = G2 < 0 ? 0 : G2;
					*(pRGBData + (height - i - 1)*width * 3 + j * 6 + 3) = B2 < 0 ? 0 : B2;
				}
			}
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
// RGB2YUV
// pRGB			point to the RGB data
// pYUV			point to the YUV data
// width		width of the picture
// height		height of the picture
// alphaYUV		is there an alpha channel in YUV
// alphaRGB		is there an alpha channel in RGB
//////////////////////////////////////////////////////////////////////////
int RGB2YUV(void* pRGB, void* pYUV, int width, int height, bool alphaYUV, bool alphaRGB)
{
	if (NULL == pRGB)
	{
		return -1;
	}
	unsigned char* pRGBData = (unsigned char *)pRGB;
	unsigned char* pYUVData = (unsigned char *)pYUV;
	if (NULL == pYUVData)
	{
		if (alphaYUV)
		{
			pYUVData = new unsigned char[width*height * 3];
		}
		else
			pYUVData = new unsigned char[width*height * 2];
	}
	int R1, G1, B1, R2, G2, B2, Y1, U1, Y2, V1;
	int alpha1, alpha2;
	if (alphaYUV)
	{
		if (alphaRGB)
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					B1 = *(pRGBData + (height - i - 1)*width * 4 + j * 8);
					G1 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 1);
					R1 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 2);
					alpha1 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 3);
					B2 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 4);
					G2 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 5);
					R2 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 6);
					alpha2 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 7);
					Y1 = (((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16) > 255 ? 255 : (((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16);
					U1 = ((((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8) + ((-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8)) / 2 + 128) > 255 ? 255 : ((((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8) + ((-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8)) / 2 + 128);
					Y2 = (((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16) > 255 ? 255 : ((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16;
					V1 = ((((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8) + ((112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8)) / 2 + 128) > 255 ? 255 : ((((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8) + ((112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8)) / 2 + 128);
					*(pYUVData + i*width * 3 + j * 6) = Y1;
					*(pYUVData + i*width * 3 + j * 6 + 1) = U1;
					*(pYUVData + i*width * 3 + j * 6 + 2) = Y2;
					*(pYUVData + i*width * 3 + j * 6 + 3) = V1;
					*(pYUVData + i*width * 3 + j * 6 + 4) = alpha1;
					*(pYUVData + i*width * 3 + j * 6 + 5) = alpha2;
				}
			}
		}
		else
		{
			unsigned char alpha = 255;
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					B1 = *(pRGBData + (height - i - 1)*width * 3 + j * 6);
					G1 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 1);
					R1 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 2);
					B2 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 3);
					G2 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 4);
					R2 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 5);
					Y1 = ((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16;
					U1 = ((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8 + (-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8) / 2 + 128;
					Y2 = ((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16;
					V1 = ((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8 + (112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8) / 2 + 128;
					Y1 = (((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16) > 255 ? 255 : (((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16);
					U1 = ((((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8) + ((-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8)) / 2 + 128) > 255 ? 255 : ((((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8) + ((-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8)) / 2 + 128);
					Y2 = (((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16) > 255 ? 255 : ((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16;
					V1 = ((((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8) + ((112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8)) / 2 + 128) > 255 ? 255 : ((((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8) + ((112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8)) / 2 + 128);
					*(pYUVData + i*width * 3 + j * 6) = Y1;
					*(pYUVData + i*width * 3 + j * 6 + 1) = U1;
					*(pYUVData + i*width * 3 + j * 6 + 2) = Y2;
					*(pYUVData + i*width * 3 + j * 6 + 3) = V1;
					*(pYUVData + i*width * 3 + j * 6 + 4) = alpha;
					*(pYUVData + i*width * 3 + j * 6 + 5) = alpha;
				}
			}
		}
	}
	else
	{
		if (alphaRGB)
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					B1 = *(pRGBData + (height - i - 1)*width * 4 + j * 8);
					G1 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 1);
					R1 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 2);
					B2 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 4);
					G2 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 5);
					R2 = *(pRGBData + (height - i - 1)*width * 4 + j * 8 + 6);
					Y1 = (((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16) > 255 ? 255 : (((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16);
					U1 = ((((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8) + ((-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8)) / 2 + 128) > 255 ? 255 : ((((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8) + ((-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8)) / 2 + 128);
					Y2 = (((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16) > 255 ? 255 : ((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16;
					V1 = ((((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8) + ((112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8)) / 2 + 128) > 255 ? 255 : ((((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8) + ((112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8)) / 2 + 128);
					*(pYUVData + i*width * 2 + j * 4) = Y1;
					*(pYUVData + i*width * 2 + j * 4 + 1) = U1;
					*(pYUVData + i*width * 2 + j * 4 + 2) = Y2;
					*(pYUVData + i*width * 2 + j * 4 + 3) = V1;
				}
			}
		}
		else
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					B1 = *(pRGBData + (height - i - 1)*width * 3 + j * 6);
					G1 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 1);
					R1 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 2);
					B2 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 3);
					G2 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 4);
					R2 = *(pRGBData + (height - i - 1)*width * 3 + j * 6 + 5);
					Y1 = (((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16) > 255 ? 255 : (((66 * R1 + 129 * G1 + 25 * B1 + 128) >> 8) + 16);
					U1 = ((((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8) + ((-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8)) / 2 + 128) > 255 ? 255 : ((((-38 * R1 - 74 * G1 + 112 * B1 + 128) >> 8) + ((-38 * R2 - 74 * G2 + 112 * B2 + 128) >> 8)) / 2 + 128);
					Y2 = (((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16) > 255 ? 255 : ((66 * R2 + 129 * G2 + 25 * B2 + 128) >> 8) + 16;
					V1 = ((((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8) + ((112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8)) / 2 + 128) > 255 ? 255 : ((((112 * R1 - 94 * G1 - 18 * B1 + 128) >> 8) + ((112 * R2 - 94 * G2 - 18 * B2 + 128) >> 8)) / 2 + 128);
					*(pYUVData + i*width * 2 + j * 4) = Y1;
					*(pYUVData + i*width * 2 + j * 4 + 1) = U1;
					*(pYUVData + i*width * 2 + j * 4 + 2) = Y2;
					*(pYUVData + i*width * 2 + j * 4 + 3) = V1;
				}
			}
		}
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////
// pGBYUV			point to the background YUV data
// pFGYUV			point to the foreground YUV data
// width			width of the picture
// height			height of the picture
// alphaBG			is there an alpha channel in background YUV data
// alphaFG			is there an alpha channel in fourground YUV data
//////////////////////////////////////////////////////////////////////////
int YUVBlending(void* pBGYUV, void* pFGYUV, int width, int height, bool alphaBG, bool alphaFG)
{
	if (NULL == pBGYUV || NULL == pFGYUV)
	{
		return -1;
	}
	unsigned char* pBGData = (unsigned char*)pBGYUV;
	unsigned char* pFGData = (unsigned char*)pFGYUV;
	if (!alphaFG)
	{
		if (!alphaBG)
		{
			memcpy(pBGData, pFGData, width*height * 2);
		}
		else
		{
			for (int i = 0; i < height; ++i)
			{
				for (int j = 0; j < width / 2; ++j)
				{
					*(pBGData + i*width * 2 + j * 4) = *(pFGData + i*width * 2 + j * 4);
					*(pBGData + i*width * 2 + j * 4 + 1) = *(pFGData + i*width * 2 + j * 4 + 1);
					*(pBGData + i*width * 2 + j * 4 + 2) = *(pFGData + i*width * 2 + j * 4 + 2);
					*(pBGData + i*width * 2 + j * 4 + 3) = *(pFGData + i*width * 2 + j * 4 + 3);
				}
			}
		}
	}
	int Y11, U11, V11, Y12, Y21, U21, V21, Y22;
	int alpha1, alpha2;
	if (!alphaBG)
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width / 2; ++j)
			{
				Y11 = *(pBGData + i*width * 2 + j * 4);
				U11 = *(pBGData + i*width * 2 + j * 4 + 1);
				Y12 = *(pBGData + i*width * 2 + j * 4 + 2);
				V11 = *(pBGData + i*width * 2 + j * 4 + 3);

				Y21 = *(pFGData + i*width * 3 + j * 6);
				U21 = *(pFGData + i*width * 3 + j * 6 + 1);
				Y22 = *(pFGData + i*width * 3 + j * 6 + 2);
				V21 = *(pFGData + i*width * 3 + j * 6 + 3);
				alpha1 = *(pFGData + i*width * 3 + j * 6 + 4);
				alpha2 = *(pFGData + i*width * 3 + j * 6 + 5);

				*(pBGData + i*width * 2 + j * 4) = (Y21 - 16)*alpha1 / 255 + (Y11 - 16)*(255 - alpha1) / 255 + 16;
				*(pBGData + i*width * 2 + j * 4 + 1) = ((U21 - 128)*alpha1 / 255 + (U11 - 128)*(255 - alpha1) / 255 + (U21 - 128)*alpha2 / 255 + (U11 - 128)*(255 - alpha2) / 255) / 2 + 128;
				*(pBGData + i*width * 2 + j * 4 + 3) = ((V21 - 128)*alpha1 / 255 + (V11 - 128)*(255 - alpha1) / 255 + (V21 - 128)*alpha2 / 255 + (V11 - 128)*(255 - alpha2) / 255) / 2 + 128;
				*(pBGData + i*width * 2 + j * 4 + 2) = (Y22 - 16)*alpha2 / 255 + (Y12 - 16)*(255 - alpha2) / 255 + 16;
			}
		}
	}
	else
	{
		for (int i = 0; i < height; ++i)
		{
			for (int j = 0; j < width / 2; ++j)
			{
				Y11 = *(pBGData + i*width * 3 + j * 6);
				U11 = *(pBGData + i*width * 3 + j * 6 + 1);
				Y12 = *(pBGData + i*width * 3 + j * 6 + 2);
				V11 = *(pBGData + i*width * 3 + j * 6 + 3);

				Y21 = *(pFGData + i*width * 3 + j * 6);
				U21 = *(pFGData + i*width * 3 + j * 6 + 1);
				Y22 = *(pFGData + i*width * 3 + j * 6 + 2);
				V21 = *(pFGData + i*width * 3 + j * 6 + 3);
				alpha1 = *(pFGData + i*width * 3 + j * 6 + 4);
				alpha2 = *(pFGData + i*width * 3 + j * 6 + 5);

				*(pBGData + i*width * 3 + j * 6) = (Y21 - 16)*alpha1 / 255 + (Y11 - 16)*(255 - alpha1) / 255 + 16;
				*(pBGData + i*width * 3 + j * 6 + 1) = ((U21 - 128)*alpha1 / 255 + (U11 - 128)*(255 - alpha1) / 255 + (U21 - 128)*alpha2 / 255 + (U11 - 128)*(255 - alpha2) / 255) / 2 + 128;
				*(pBGData + i*width * 3 + j * 6 + 3) = ((V21 - 128)*alpha1 / 255 + (V11 - 128)*(255 - alpha1) / 255 + (V21 - 128)*alpha2 / 255 + (V11 - 128)*(255 - alpha2) / 255) / 2 + 128;
				*(pBGData + i*width * 3 + j * 6 + 2) = (Y22 - 16)*alpha2 / 255 + (Y12 - 16)*(255 - alpha2) / 255 + 16;
			}
		}
	}
	return 0;
}

BOOL CSGCallbackHandler::SaveBitmap(BYTE * pBuffer, long lBufferSize)
{

	CString path;
	path.Format(_T("%ld.bmp"), m_nImageCount);
	if (m_szExportDir.Right(1) != _T("\\"))
		m_szExportDir += _T("\\");
	path = m_szExportDir + m_szExportName;
	LPCTSTR m_szFileName = path.GetBuffer(0);
	HANDLE hf = CreateFile(m_szFileName, GENERIC_WRITE,
		FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, 0, NULL);
	path.ReleaseBuffer();
	if (hf == INVALID_HANDLE_VALUE)
	{
		return E_FAIL;
	}
	long cbBitmapInfoSize = g_StillMediaType.cbFormat - SIZE_PREHEADER;
	VIDEOINFOHEADER *pVideoHeader =
		(VIDEOINFOHEADER*)g_StillMediaType.pbFormat;
	BITMAPFILEHEADER bfh;
	ZeroMemory(&bfh, sizeof(bfh));
	bfh.bfType = 'MB';  // Little-endian for "BM".
	bfh.bfSize = sizeof(bfh) + lBufferSize + cbBitmapInfoSize;
	bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + cbBitmapInfoSize;

	// Write the file header.
	DWORD dwWritten = 0;
	WriteFile(hf, &bfh, sizeof(bfh), &dwWritten, NULL);
	WriteFile(hf, HEADER(pVideoHeader), cbBitmapInfoSize, &dwWritten, NULL);
	WriteFile(hf, pBuffer, lBufferSize, &dwWritten, NULL);
	CloseHandle(hf);	
	return 0;
}
//-----------------------------------------------------------------------------

// Constuctor
//
CSGCallbackHandler::CSGCallbackHandler()
{
	m_nWidth = 0;
	m_nHeight = 0;
	m_pPlayer = NULL;
	m_pKeyFrameProcessor = NULL;
	m_nImageSize = 0;
	m_pImageBuffer = NULL;
	// Initialize GDI+.  
	//greenPen = new Pen(Color::Green, 3.0f);
	m_szExportDir = _T("c:\\a5\\");
	m_szExportName = _T("iris1.jpg");
	m_nExportWidh = 640;
	m_nExportHeight = 480;
	m_nCompressRatio = 30;
	m_nCaptureFreq = 8;
	m_nFramePerSec = 15;


}

//-----------------------------------------------------------------------------
// Destructor
//
CSGCallbackHandler::~CSGCallbackHandler(void)
{
	if (m_pKeyFrameProcessor != NULL)
		KF_FreeObject((void*)m_pKeyFrameProcessor);

}

//-----------------------------------------------------------------------------
// QueryInterface
//
STDMETHODIMP CSGCallbackHandler::QueryInterface(REFIID riid, void **ppv)
{
	HRESULT hr = S_OK;

	if ((riid == IID_ISampleGrabberCB) || (riid == IID_IUnknown))
	{
		*ppv = (void*)static_cast<ISampleGrabberCB*>(this);
	}
	else
	{
		hr = E_NOINTERFACE;
	}

	return hr;
}


// Initial Class
HRESULT CSGCallbackHandler::InitKeyFrameProcessor(CBasicParams* pBasicParams)
{
	if (m_pKeyFrameProcessor != NULL)
		SAFE_DELETE(m_pKeyFrameProcessor);
	HRESULT hr = KF_CreateObject((void**)&m_pKeyFrameProcessor);
	if (FAILED(hr))
		return hr;

	hr = KF_SetBasicParams((void*)m_pKeyFrameProcessor, (void*)pBasicParams);
	return hr;
}
//-----------------------------------------------------------------------------
// ISampleGrabberCB interface
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// SampleCB
// Callback for sample grabber interface which provides a media sample
STDMETHODIMP CSGCallbackHandler::SampleCB(double SampleTime, IMediaSample* pSample)
{
	HRESULT hr = S_OK;
	AM_MEDIA_TYPE* mt = new AM_MEDIA_TYPE;
	long cbData;
	BYTE* pData = NULL;
	long lDataLen;
	pSample->GetMediaType(&mt);
	m_nImageCount++;
	if (m_nImageCount % 5 != 0)
		return S_OK;

	if (pSample)
	{
		cbData = pSample->GetActualDataLength();
		hr = pSample->GetPointer(&pData);
		lDataLen = pSample->GetSize();
		//if (SUCCEEDED(hr))
		//{
		//	hr = m_pCtrl->SetBuffer(reinterpret_cast<const unsigned char*>(pData), cbData);
		//}
	}
	else
	{
		hr = E_POINTER;
	}
	
	return hr;
}

//-----------------------------------------------------------------------------
// BufferCB
// Callback for sample grabber interface which provides a buffer
STDMETHODIMP CSGCallbackHandler::BufferCB(double SampleTime, BYTE* pBuffer, long BufferLen)
{
	if ((g_StillMediaType.majortype != MEDIATYPE_Video) ||
		(g_StillMediaType.formattype != FORMAT_VideoInfo) ||
		(g_StillMediaType.cbFormat < sizeof(VIDEOINFOHEADER)) ||
		(g_StillMediaType.pbFormat == NULL))
	{
		return VFW_E_INVALIDMEDIATYPE;
	}	
	CString str;
	str.Format(_T("duration:%lf\n"), SampleTime);
	TRACE(str);
	HRESULT hr = S_OK;
	long nFrameID = 0;
	m_nImageCount++;
	//if ((m_nImageCount % m_nCaptureFreq) != 0)
	//	return hr;
	if (pBuffer)
	{
		if (!m_bEnable)
			return hr;
//		SaveImage(SampleTime, pBuffer, BufferLen);
		SaveBitmap(pBuffer, BufferLen);
		//if (m_nMode == JBU_FACE_DETECTION_MODE)
		m_nImageCount = 0;
	}
	else
	{
		hr = E_POINTER;
	}
	
	return hr;
}

void CSGCallbackHandler::SaveDataFile()
{
	KF_Save(m_pKeyFrameProcessor);
}

HRESULT CSGCallbackHandler::SaveImage(double SampleTime, BYTE* pImagePixel, long nImageLength)
{
	HRESULT hr = S_OK;
	int nBpp;
	CString str;
	long nIndex;

	//yuy2 2 RGB
	//m_nBitPerPixel = 24;
	BYTE* pRgb = NULL;
	//m_nBitPerPixel = 24;
	m_nWidth = 640;
	m_nHeight = 360;
	long nImageSize = m_nWidth * m_nHeight * m_nBitPerPixel / 8;
	TRY 
	{
		pRgb = new BYTE[nImageSize];
	}
	CATCH (CMemoryException, e)
	{
		return S_FALSE;
	}
	END_CATCH
	ZeroMemory(pRgb, nImageSize);
//	YUV2RGB(pImagePixel, pRgb, m_nWidth, m_nHeight, false, true);
	YUVBlending(pImagePixel, pRgb, m_nWidth, m_nHeight, false, true);
	if (m_nBitPerPixel == 8)
		nBpp = 0;
	else
		nBpp = m_nBitPerPixel;
	return hr;
}

void CSGCallbackHandler::EnableCapture(LONG nEnable)
{
	m_bEnable = (BOOL)nEnable;
}

