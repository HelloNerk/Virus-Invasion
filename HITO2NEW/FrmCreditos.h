#pragma once

namespace HITO2NEW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmCreditos
	/// </summary>
	public ref class FrmCreditos : public System::Windows::Forms::Form
	{
	public:
		FrmCreditos(void)
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
		~FrmCreditos()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmCreditos::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::LightBlue;
			this->label1->Location = System::Drawing::Point(96, 18);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(280, 54);
			this->label1->TabIndex = 3;
			this->label1->Text = L"ALGORITMOS";
			this->label1->Click += gcnew System::EventHandler(this, &FrmCreditos::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::AliceBlue;
			this->label2->Location = System::Drawing::Point(158, 86);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 28);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Sección: SW21";
			this->label2->Click += gcnew System::EventHandler(this, &FrmCreditos::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::AliceBlue;
			this->label3->Location = System::Drawing::Point(58, 125);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(357, 28);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Profesor: Jorge Eduardo Diaz Suarez";
			this->label3->Click += gcnew System::EventHandler(this, &FrmCreditos::label3_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Black", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::AliceBlue;
			this->label4->Location = System::Drawing::Point(167, 170);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(132, 28);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Integrantes:";
			this->label4->Click += gcnew System::EventHandler(this, &FrmCreditos::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::AliceBlue;
			this->label5->Location = System::Drawing::Point(67, 215);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(351, 25);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Jeremy Joel Quispe Andia (u202216279)";
			this->label5->Click += gcnew System::EventHandler(this, &FrmCreditos::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::AliceBlue;
			this->label6->Location = System::Drawing::Point(34, 253);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(406, 25);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Hernan Emilio Morales Calderón (u202216263)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::AliceBlue;
			this->label7->Location = System::Drawing::Point(22, 296);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(434, 25);
			this->label7->TabIndex = 9;
			this->label7->Text = L"Joseph Alexis Huamani Mandujano (u20221A133)";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->BackColor = System::Drawing::Color::Transparent;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Lavender;
			this->label8->Location = System::Drawing::Point(163, 341);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(154, 54);
			this->label8->TabIndex = 10;
			this->label8->Text = L"2022-2";
			this->label8->Click += gcnew System::EventHandler(this, &FrmCreditos::label8_Click);
			// 
			// FrmCreditos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(485, 520);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"FrmCreditos";
			this->Text = L"Creditos";
			this->Load += gcnew System::EventHandler(this, &FrmCreditos::FrmCreditos_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void FrmCreditos_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label8_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
