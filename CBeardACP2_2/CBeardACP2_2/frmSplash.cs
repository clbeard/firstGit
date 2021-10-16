using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace CBeardACP2_2
{
    public partial class frmSplash : Form
    {
        public frmSplash()
        {
            InitializeComponent();
        }
        public int timeLeft { get; set; }

        private void frmSplash_Load(object sender, EventArgs e)
        {
            timeLeft = 150;
            tmrSplash.Start();
            bkgWorker.WorkerReportsProgress = true;
            bkgWorker.RunWorkerAsync();
        }

        private void bkgWorker_DoWork(object sender, DoWorkEventArgs e)
        {

            for (int i = 1; i <= 100; i++)
            {
                Thread.Sleep(50);
                bkgWorker.ReportProgress(i);
            }
        }

        private void bkgWorker_ProgressChanged(object sender, ProgressChangedEventArgs e)
        {
            pgrbarSplash.Value = e.ProgressPercentage;
            lblProgress.Text = "Progress: " + e.ProgressPercentage.ToString() + "%";
            if (pgrbarSplash.Value >= 100)
            {

                MessageBox.Show("Your Application is open.");

                frmMain myForm = new frmMain();
                this.Hide();
                myForm.ShowDialog();
                this.Close();
            }
        }

        private void tmrSplash_Tick(object sender, EventArgs e)
        {
            if (timeLeft > 0)
            {
                timeLeft = timeLeft - 1;

            }
            else
            {
                tmrSplash.Stop();
                // new frmMain().Show();
                //this.Hide();



            }
        }
    }
}
