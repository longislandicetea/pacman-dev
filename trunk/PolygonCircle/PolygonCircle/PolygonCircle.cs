using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace PolygonCircle
{
    class PolygonCircle
    {
        private int n;
        private double a, b;
        private Point now;
        private Bitmap map;

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

        public PolygonCircle(int r,Bitmap _map)
        {
            n = (int)(2 * Math.PI * r);
            float af = 1.0f / r;
            b = Math.Cos(af);
            a = Math.Sin(af);
            now.X = r;
            now.Y = 0;
            map = _map;
        }

        public void customDraw(float x, float y) 
        {
            drawPixel((int)x + 300, (int)y + 200, Color.Red);
        }
        
        public void Draw()
        {
            float x, y;
            x = now.X;
            y = 0.0f;
            int cnt = 0;
            int[,] f = new int[,]{{1,1},{-1,1},{1,-1},{-1,-1}};
            while (cnt<n/4)
            {
                for (int i = 0; i < 4; ++i)
                {
                    customDraw(x * f[i, 0], y * f[i, 1]);
                }
                float oldx = x, oldy = y;
                x = (float)(b * oldx - a * oldy);
                y = (float)(a * oldx + b * oldy);
                ++cnt;
            }
        }
    }
}
