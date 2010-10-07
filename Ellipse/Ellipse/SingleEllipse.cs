using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Ellipse
{
    class SingleEllipse
    {
        private int a, b;
        private Point now;
        private float d1, d2;
        private Bitmap map;
        private int offsetX,offsetY;

        private void drawPixel(int posX, int posY, Color color)
        {
            Bitmap tmp = new Bitmap(2, 2);
            for (int i = 0; i < 2; ++i)
            {
                for (int j = 0; j < 2; ++j)
                {
                    tmp.SetPixel(i, j, Color.Red);
                }
            }
            Graphics g = Graphics.FromImage(map);
            g.DrawImageUnscaled(tmp, posX, posY);
        }

        private void drawFourPoint(Point now, Color color)
        {
            drawPixel(now.X+offsetX, now.Y+offsetY, color);
            drawPixel(-now.X+offsetX, now.Y+offsetY, color);
            drawPixel(now.X+offsetX, -now.Y+offsetY, color);
            drawPixel(-now.X+offsetX, -now.Y+offsetY, color);
        }

        public SingleEllipse(int _a, int _b,Bitmap _map)
        {
            a = _a;
            b = _b;
            map = _map;
            now.X = 0;
            now.Y = b;
            d1 = (float)(b * b + a * a * (-b + 0.25));
            offsetX = 300;
            offsetY = 200;
        }

        private float sqr(float x)
        {
            return x * x;
        }

        public void Draw()
        {
            while (b * b * (now.X + 1) < a * a * (now.Y - 0.5))
            {
                if (d1 < 0)
                {
                    d1 += b * b * (2 * now.X + 3);
                    ++now.X;
                }
                else
                {
                    d1 += b * b * (2 * now.X + 3) + a * a * (-2 * now.Y + 2);
                    ++now.X;
                    --now.Y;
                }
                drawFourPoint(now, Color.Red);
            }
            d2 = sqr((float)(b * (now.X + 0.5))) + sqr((float)(a * (now.Y - 1))) - sqr((float)(a * b));
            while (now.Y > 0)
            {
                if (d2 < 0)
                {
                    d2 += b * b * (2 * now.X + 2) + a * a * (-2 * now.Y + 3);
                    ++now.X;
                    --now.Y;
                }
                else
                {
                    d2 += a * a * (-2 * now.Y + 3);
                    --now.Y;
                }
                drawFourPoint(now, Color.Red);
            }
        }
    }
}
