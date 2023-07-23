#pragma once
#include "FrmCreditos.h"
#include "FrmInstrucciones.h"
#include "FrmDificultad1.h"

namespace HITO2NEW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FrmStart
	/// </summary>
	public ref class FrmStart : public System::Windows::Forms::Form
	{
	public:
		FrmStart(void)
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
		~FrmStart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnJugar;

	protected:


	private: System::Windows::Forms::Button^ btnInstrucciones;
	private: System::Windows::Forms::Button^ btnCreditos;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FrmStart::typeid));
			this->btnJugar = (gcnew System::Windows::Forms::Button());
			this->btnInstrucciones = (gcnew System::Windows::Forms::Button());
			this->btnCreditos = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btnJugar
			// 
			this->btnJugar->Location = System::Drawing::Point(233, 153);
			this->btnJugar->Name = L"btnJugar";
			this->btnJugar->Size = System::Drawing::Size(95, 40);
			this->btnJugar->TabIndex = 0;
			this->btnJugar->Text = L"Jugar";
			this->btnJugar->UseVisualStyleBackColor = true;
			this->btnJugar->Click += gcnew System::EventHandler(this, &FrmStart::btnJugar_Click);
			// 
			// btnInstrucciones
			// 
			this->btnInstrucciones->Location = System::Drawing::Point(215, 265);
			this->btnInstrucciones->Name = L"btnInstrucciones";
			this->btnInstrucciones->Size = System::Drawing::Size(127, 41);
			this->btnInstrucciones->TabIndex = 3;
			this->btnInstrucciones->Text = L"Instrucciones";
			this->btnInstrucciones->UseVisualStyleBackColor = true;
			this->btnInstrucciones->Click += gcnew System::EventHandler(this, &FrmStart::btnInstrucciones_Click);
			// 
			// btnCreditos
			// 
			this->btnCreditos->Location = System::Drawing::Point(231, 207);
			this->btnCreditos->Name = L"btnCreditos";
			this->btnCreditos->Size = System::Drawing::Size(95, 41);
			this->btnCreditos->TabIndex = 1;
			this->btnCreditos->Text = L"Créditos";
			this->btnCreditos->UseVisualStyleBackColor = true;
			this->btnCreditos->Click += gcnew System::EventHandler(this, &FrmStart::btnCreditos_Click);
			// 
			// FrmStart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(565, 520);
			this->Controls->Add(this->btnInstrucciones);
			this->Controls->Add(this->btnCreditos);
			this->Controls->Add(this->btnJugar);
			this->Name = L"FrmStart";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Juego";
			this->Load += gcnew System::EventHandler(this, &FrmStart::FrmStart_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnJugar_Click(System::Object^ sender, System::EventArgs^ e) {
		FrmDificultad^ frm = gcnew FrmDificultad();
		frm->Show();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void btnCreditos_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmCreditos^ frm = gcnew FrmCreditos();
	frm->Show();
}
private: System::Void btnInstrucciones_Click(System::Object^ sender, System::EventArgs^ e) {
	FrmInstrucciones^ frm = gcnew FrmInstrucciones();
	frm->Show();
}
private: System::Void FrmStart_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
