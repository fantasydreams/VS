using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace Video
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btStartPlay_Click(object sender, EventArgs e)
        {
            if (this.IsValid())
            {
                int nPort = int.Parse(this.tbPort.Text);
                short nChannel = short.Parse(this.tbChannel.Text);
                bool bSuccess = this.axRealPlayX1.SetDeviceInfo(this.tbDvrIP.Text, nPort, nChannel, this.tbUserName.Text, this.tbPwd.Text);
                if (bSuccess)
                {
                    bSuccess = this.axRealPlayX1.StartPlay();
                }
            }
            else
            {
                MessageBox.Show("Input is empty£¡", "prompt");
            }
        }

        private bool IsValid()
        {
            bool bValid = true;
            if (this.tbDvrIP.Text == "" || this.tbPort.Text == "" || this.tbChannel.Text == "" 
                || this.tbUserName.Text == "")
            {
                bValid = false;
            }
            return bValid;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            this.axRealPlayX1.StopPlay();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}