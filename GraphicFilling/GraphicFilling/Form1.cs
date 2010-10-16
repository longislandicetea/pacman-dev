using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace GraphicFilling
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            map  = new Bitmap(600,600);
        }
        private Bitmap map;

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = Graphics.FromHwnd(this.Handle);
            g.DrawImageUnscaled(map, 0, 0); 
            
            List<Point> points = new List<Point>();
            Point[] tmp = new Point[5];
            tmp[0] = new Point(6, 1);
            tmp[1] = new Point(8, 5);
            tmp[2] = new Point(6, 7);
            tmp[3] = new Point(2, 6);
            tmp[4] = new Point(2, 3);
            for (int i = 0; i < 5; ++i)
                points.Add(tmp[i]);

            Graphic graphic = new Graphic(points, map);
            graphic.Fill();
        }
    }
}
