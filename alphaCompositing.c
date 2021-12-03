void alpha_composite(unsigned int image[][SIZE], unsigned int width, unsigned int height, float alpha, int background_color)
{
	for(int i=0; i<height;i++){
		for(int j=0;j<width;j++){
			image[i][j] = (image[i][j] * alpha + background_color * 1 * (1 - alpha)) / (alpha + 1 * (1 - alpha));
		}
	}
}

