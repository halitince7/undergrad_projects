/****************************************************************************
** SAKARYA ÜNİVERSİTESİ
** BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
** BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
** NESNEYE DAYALI PROGRAMLAMA DERSİ
**
** ÖDEV NUMARASI: Odev2 
** ÖĞRENCİ ADI.:  Halit İnce
** ÖĞRENCİ NUMARASI: b171210001
** DERS GRUBU: 1A
****************************************************************************/


using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ndp_odev2
{
    public partial class Form2 : Form
    {
        

        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 frm1 = new Form1();
            frm1.Show();
            this.Hide();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            StreamWriter dosya = File.AppendText("veriler.txt");
            if      (radioButton1.Checked) dosya.Write("k");
            else if (radioButton2.Checked) dosya.Write("m");
            else if (radioButton3.Checked) dosya.Write("y");

            if      (radioButton4.Checked) dosya.Write("k");
            else if (radioButton5.Checked) dosya.Write("m");
            else if (radioButton6.Checked) dosya.Write("y");

            if      (radioButton7.Checked) dosya.Write("k");
            else if (radioButton8.Checked) dosya.Write("m");
            else if (radioButton9.Checked) dosya.Write("y");


            dosya.WriteLine(" " + textBox1.Text + " " + textBox2.Text + " " + textBox3.Text);
            dosya.Close();
        }

        private void button4_Click(object sender, EventArgs e)
        {
            textBox1.Text = null;
            textBox2.Text = null;
            textBox3.Text = null;
            radioButton1.Checked = false;
            radioButton2.Checked = false;
            radioButton3.Checked = false;
            radioButton4.Checked = false;
            radioButton5.Checked = false;
            radioButton6.Checked = false;
            radioButton7.Checked = false;
            radioButton8.Checked = false;
            radioButton9.Checked = false;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
