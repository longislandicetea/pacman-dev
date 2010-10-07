using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;

namespace Ellipse
{
    class WideEllipse
    {
        private int a, b, width;
        private float e;
        private Bitmap map;

        public WideEllipse(int _a, int _b, int _width,Bitmap _map)
        {
            a = _a;
            b = _b;
            width = _width;
            e = (float)a /(float) b;
            map = _map;
        }

        public void Draw()
        {
            for (int i = 0; i < width; ++i)
            {
                SingleEllipse ellipse = new SingleEllipse(a, b,map);
                ellipse.Draw();
                a = (int)(a - e);
                --b;
            }
        }

    }
}
