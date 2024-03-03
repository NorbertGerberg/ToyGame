using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.IO.Compression;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ToyGame4Windows
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            using (var folderBrowserDialog = new FolderBrowserDialog())
            {
                DialogResult result = folderBrowserDialog.ShowDialog();

                if (result == DialogResult.OK && !string.IsNullOrWhiteSpace(folderBrowserDialog.SelectedPath))
                    projectPathBox.Text = folderBrowserDialog.SelectedPath;
            }
        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void websiteToolStripMenuItem_Click(object sender, EventArgs e)
        {
            string url = "https://norbertgerberg.github.io/Website/";
            try
            {
                Process.Start(url);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Failed to open website: " + ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            string projectName = projectNameBox.Text;
            string projectPath = projectPathBox.Text;

            if (!string.IsNullOrWhiteSpace(projectName) && !string.IsNullOrEmpty(projectPath))
            {
                if (!Directory.Exists(projectPath))
                    Directory.CreateDirectory(projectPath);

                if(!File.Exists("files.pck"))
                {
                    MessageBox.Show("'files.pck' could not be found.");
                    return;
                }

                ZipFile.ExtractToDirectory("files.pck", projectPath);

                string slnName = File.ReadAllText(projectPath + "\\ToyGame.sln");
                slnName = slnName.Replace("PROJECT", projectName);
                File.WriteAllText(projectPath + "\\" + projectName + ".sln", slnName);
                File.Delete(projectPath + "\\ToyGame.sln");

                slnName = File.ReadAllText(projectPath + "\\PROJECT\\PROJECT.vcxproj");
                File.WriteAllText(projectPath + "\\PROJECT\\" + projectName + ".vcxproj", slnName);
                File.Delete(projectPath + "\\PROJECT\\PROJECT.vcxproj");

                slnName = File.ReadAllText(projectPath + "\\PROJECT\\PROJECT.vcxproj.filters");
                File.WriteAllText(projectPath + "\\PROJECT\\" + projectName + ".vcxproj.filters", slnName);
                File.Delete(projectPath + "\\PROJECT\\PROJECT.vcxproj.filters");

                slnName = File.ReadAllText(projectPath + "\\PROJECT\\PROJECT.vcxproj.user");
                File.WriteAllText(projectPath + "\\PROJECT\\" + projectName + ".vcxproj.user", slnName);
                File.Delete(projectPath + "\\PROJECT\\PROJECT.vcxproj.user");

                Directory.Move(projectPath + "\\PROJECT", projectPath + "\\" + projectName);
                Directory.Delete(projectPath + "\\PROJECT");

                MessageBox.Show("Successfully created project!");
            }
        }
    }
}
