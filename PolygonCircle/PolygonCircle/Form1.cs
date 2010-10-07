using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace PolygonCircle
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            map = new Bitmap(600, 600);
        }

        private Bitmap map;

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = Graphics.FromHwnd(this.Handle);
            g.DrawImageUnscaled(map, 0, 0);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            PolygonCircle c = new PolygonCircle(Int32.Parse(this.textBox1.Text), map);
            c.Draw();
            Invalidate();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            map = new Bitmap(600, 600);
            Invalidate();
        }
    }
}
