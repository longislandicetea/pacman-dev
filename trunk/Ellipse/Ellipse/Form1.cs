using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace Ellipse
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            map = new Bitmap(600, 600);
        }

        private Bitmap map;

        private void button1_Click(object sender, EventArgs e)
        {
            WideEllipse ellipse= new WideEllipse(Int32.Parse(this.textBox1.Text), Int32.Parse(this.textBox2.Text), Int32.Parse(this.textBox3.Text),map);
            //WideEllipse ellipse = new WideEllipse(50, 40, 2,map);
            ellipse.Draw();
            Invalidate();

        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        { 
            Graphics g = Graphics.FromHwnd(this.Handle);
            g.DrawImageUnscaled(map, 0, 0);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            map = new Bitmap(600, 600);
            Invalidate();
        }
    }
}
