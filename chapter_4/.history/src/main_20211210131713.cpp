#include "postprocessing.h"

#include <stdio.h>

int main(int argc, char* argv[])
{
	//全矩阵函数路径
	const char* fmc_file_path = "../resources/1.fmc";
	//char* fmc_file_path = "F:/LEARNING/NDT/Full Matrix Algorithm/FMC Data/simu_hole.fmc";

	auto [full_matrix, N, Nt, rate] = loadFMC(fmc_file_path);

	printf("晶片数：%d，波点数： %d 频率%f\n", N, Nt, rate);

	const float kstart_x = -20e-3f;
	const float kstart_z = 0e-3f;
	const float kLx = 100e-3f;
	const float kLz = 100e-3f;
	const float kdx= 0.5e-3f;
	const float kdz = 0.5e-3f;
	const float pitch = 0.6e-3f;
	const float kc = 5900.0f;
	const float kwc = 2337.0f;

	//直接耦合的晶片坐标
	std::vector <float> xt1(N);
	std::vector <float> zt1(N);
	for (int i = 0; i < N; i++)
	{
		xt1[i] = i * pitch;
		zt1[i] = 0;
	}

	//20mm平楔块的晶片坐标
	std::vector <float> xt2(N);
	std::vector <float> zt2(N);
	for (int i = 0; i < N; i++)
	{
		xt2[i] = i * pitch;
		zt2[i] = -20e-3;
	}

	auto [focal_law, Nx, Nz] = createFocalLawWithWedge(xt2, zt2, kstart_x, kstart_z, kLx, kLz, kdx, kdz, kc, kwc);

	auto TFM_image = createTFMImage(full_matrix, focal_law, N, Nt, Nx, Nz, rate);

	saveTFMImage("1.tfm", TFM_image, Nx, Nz);

	getchar();
	return 0;
}