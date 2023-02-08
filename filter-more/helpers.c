#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int temp = round((image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen) / 3.0);
            image[i][j].rgbtRed = temp;
            image[i][j].rgbtBlue = temp;
            image[i][j].rgbtGreen = temp;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        if (width % 2 == 0)
        {
            for (int j = 0; j < width / 2; j++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
        else
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                RGBTRIPLE temp[height][width];
                temp[i][j] = image[i][j];
                image[i][j] = image[i][width - (j + 1)];
                image[i][width - (j + 1)] = temp[i][j];
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = 0;
            float green = 0;
            float blue = 0;
            float count = 0;

            for (int l = -1; l < 2; l++)
            {
                for (int k = -1; k < 2; k++)
                {
                    if ((i + l < 0) || (i + l > height - 1))
                    {
                        continue;
                    }

                    if ((j + k < 0) || (j + k > width - 1))
                    {
                        continue;
                    }

                    red += image[i + l][j + k].rgbtRed;
                    green += image[i + l][j + k].rgbtGreen;
                    blue += image[i + l][j + k].rgbtBlue;
                    count++;
                }
            }

            temp[i][j].rgbtRed = round(red / count);
            temp[i][j].rgbtGreen = round(green / count);
            temp[i][j].rgbtBlue = round(blue / count);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int x[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int y[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int xRed = 0;
            int xGreen = 0;
            int xBlue = 0;
            int yRed = 0;
            int yGreen = 0;
            int yBlue = 0;

            for (int l = -1; l < 2; l++)
            {
                for (int k = -1; k < 2; k++)
                {
                    if ((i + l < 0) || (i + l > height - 1))
                    {
                        continue;
                    }

                    if ((j + k < 0) || (j + k > width - 1))
                    {
                        continue;
                    }

                    xRed += image[i + l][j + k].rgbtRed * x[l + 1][k + 1];
                    xGreen += image[i + l][j + k].rgbtGreen * x[l + 1][k + 1];
                    xBlue += image[i + l][j + k].rgbtBlue * x[l + 1][k + 1];
                    yRed += image[i + l][j + k].rgbtRed * y[l + 1][k + 1];
                    yGreen += image[i + l][j + k].rgbtGreen * y[l + 1][k + 1];
                    yBlue += image[i + l][j + k].rgbtBlue * y[l + 1][k + 1];
                }
            }

            int red = round(sqrt(xRed * xRed + yRed * yRed));
            int green = round(sqrt(xGreen * xGreen + yGreen * yGreen));
            int blue = round(sqrt(xBlue * xBlue + yBlue * yBlue));

            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
        }
    }

    return;
}
