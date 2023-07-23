#pragma once
#include "MyForm.h"
#include "MyForm1.h"
namespace HITO2NEW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmDificultad
	/// </summary>
	public ref class FrmDificultad : public System::Windows::Forms::Form
	{
	public:
		FrmDificultad(void)
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
		~FrmDificultad()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;


	protected:

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 20, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::Black;
			this->label1->Location = System::Drawing::Point(53, 130);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(381, 46);
			this->label1->TabIndex = 4;
			this->label1->Text = L"ELIGE LA DIFICULTAD\r\n";
			this->label1->Click += gcnew System::EventHandler(this, &FrmDificultad::label1_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(157, 244);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 45);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Normal";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FrmDificultad::button1_Click_1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::White;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(157, 319);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(149, 45);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Díficil";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FrmDificultad::button2_Click);
			// 
			// FrmDificultad
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Lime;
			this->ClientSize = System::Drawing::Size(485, 520);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"FrmDificultad";
			this->Text = L"Virus Invasion";
			this->Load += gcnew System::EventHandler(this, &FrmDificultad::FrmDificultad_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		MyForm^ frm = gcnew MyForm();
		frm->Show();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm1^ frm = gcnew MyForm1();
		frm->Show();
	}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void FrmDificultad_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
