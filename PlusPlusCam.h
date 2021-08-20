#pragma once
#include <opencv2/cvImagecodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/cvImageproc.hpp>



namespace PlusPlusWebCamApp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PlusPlusCam
	/// </summary>
	public ref class PlusPlusCam : public System::Windows::Forms::Form
	{
	public:
		PlusPlusCam(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PlusPlusCam()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(277, 376);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PlusPlusCam::button1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(32, 44);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(599, 279);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// PlusPlusCam
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(667, 434);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Name = L"PlusPlusCam";
			this->Text = L"PlusPlusCam";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

void Camera() {

	cv::VideoCapture capture(0);
	cv::Mat cvImage;

	while (true) {

		capture.read(cvImage);
		//imshow("Image", cvImage);

		DrawCVImage(pictureBox1, cvImage);

		//pictureBox1->Refresh();
		cv::waitKey(1);
	}

}


void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colourImage)
{
	System::Drawing::Graphics^ graphics = control->CreateGraphics();
	System::IntPtr ptr(colourImage.ptr());
	System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colourImage.cols, colourImage.rows, colourImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
	System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
	graphics->DrawImage(b, rect);
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Camera();
}
};
}
