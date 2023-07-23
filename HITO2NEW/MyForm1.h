#include <iostream>
#include "Heroe.h"
#include "Controller.h"
#include <ctime>
namespace HITO2NEW {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			srand(time(NULL));
			g = pnlCanvas->CreateGraphics();
			space = BufferedGraphicsManager::Current;
			buffer = space->Allocate(g, pnlCanvas->ClientRectangle);
			bmpheroe = gcnew Bitmap("doctor.png");
			bmpaliado = gcnew Bitmap("aliado.png");
			bmpenemy = gcnew Bitmap("enemigo2.png");
			bmpMap = gcnew Bitmap("fondo.png");
			bmpbala = gcnew Bitmap("bala.png");
			bmpmunicion = gcnew Bitmap("municion.png");
			bmpvirus = gcnew Bitmap("virus.png");
			bmpenemigocurado = gcnew Bitmap("enemigo1.png");
			heroe = new Heroe(bmpheroe->Width / 4, bmpheroe->Height / 4);
			controller = new Controller();
			tiempomunicion = clock();
			controller->juegodificil(); //modo dificil activado
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		Graphics^ g;
		BufferedGraphicsContext^ space;
		BufferedGraphics^ buffer;
		Bitmap^ bmpheroe;
		Bitmap^ bmpMap;
		Bitmap^ bmpenemy;
		Bitmap^ bmpaliado;
		Bitmap^ bmpbala;
		Bitmap^ bmpmunicion;
		Bitmap^ bmpvirus;
		Bitmap^ bmpenemigocurado;
		Heroe* heroe;
		Controller* controller;
		time_t tiempomunicion;
	private: System::Windows::Forms::Panel^ pnlCanvas;


	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Timer^ timer2;

	private: System::ComponentModel::IContainer^ components;


#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->components = (gcnew System::ComponentModel::Container());
			   this->pnlCanvas = (gcnew System::Windows::Forms::Panel());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			   this->pnlCanvas->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // pnlCanvas
			   // 
			   this->pnlCanvas->Controls->Add(this->label1);
			   this->pnlCanvas->Location = System::Drawing::Point(-3, -2);
			   this->pnlCanvas->Margin = System::Windows::Forms::Padding(4);
			   this->pnlCanvas->Name = L"pnlCanvas";
			   this->pnlCanvas->Size = System::Drawing::Size(1707, 886);
			   this->pnlCanvas->TabIndex = 0;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->label1->Location = System::Drawing::Point(20, 18);
			   this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(0, 29);
			   this->label1->TabIndex = 0;
			   // 
			   // timer1
			   // 
			   this->timer1->Enabled = true;
			   this->timer1->Tick += gcnew System::EventHandler(this, &MyForm1::timer1_Tick);
			   // 
			   // timer2
			   // 
			   this->timer2->Enabled = true;
			   this->timer2->Interval = 1000;
			   this->timer2->Tick += gcnew System::EventHandler(this, &MyForm1::timer2_Tick);
			   // 
			   // MyForm1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1707, 886);
			   this->Controls->Add(this->pnlCanvas);
			   this->Margin = System::Windows::Forms::Padding(4);
			   this->Name = L"MyForm1";
			   this->Text = L"Virus Invasion";
			   this->Load += gcnew System::EventHandler(this, &MyForm1::MyForm1_Load);
			   this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm1::MyForm1_KeyDown);
			   this->pnlCanvas->ResumeLayout(false);
			   this->pnlCanvas->PerformLayout();
			   this->ResumeLayout(false);

		   }
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		//clear
		buffer->Graphics->Clear(Color::WhiteSmoke);
		controller->collision(buffer->Graphics, heroe->getRectangle());
		controller->moveEveryThing(buffer->Graphics, heroe->getX(), heroe->getY());
		if ((clock() - tiempomunicion) / CLOCKS_PER_SEC >= 17) {
			Aliado* a = new Aliado(bmpaliado->Width / 3, bmpaliado->Height / 4);
			controller->addAliado(a);
			tiempomunicion = clock();
		}
		//draw
		buffer->Graphics->DrawImage(bmpMap, 0, 0, bmpMap->Width * 1.0, bmpMap->Height * 1.0);
		controller->createEnemies(bmpenemy->Width / 4, bmpenemy->Height / 4);
		controller->funcionaliado(bmpmunicion->Width, bmpmunicion->Height);
		controller->disparoenemigo(bmpvirus->Width, bmpvirus->Height);
		controller->drawEveryThing(buffer->Graphics, bmpenemy, bmpaliado, bmpbala, bmpmunicion, bmpvirus, bmpenemigocurado);
		heroe->draw(buffer->Graphics, bmpheroe);
		label1->Text = "Vida: " + Convert::ToString(controller->getvida()) + "\nPuntaje: " +
			Convert::ToString(controller->getpuntaje()) + "\nBalas: " + Convert::ToString(controller->getcantbalas());
		//Render
		buffer->Render(g);
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (controller->gano() == true) {
			this->Close();
			MessageBox::Show("Felicidades Ganaste" + "\nEnemigos curados: " + Convert::ToString(controller->getcurado()));
		}
		else if (controller->perdio() == true) {
			this->Close();
			MessageBox::Show("Perdiste!" + "\nEnemigos curados: " + Convert::ToString(controller->getcurado()));
		}
	}
	private: System::Void MyForm1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		switch (e->KeyCode)
		{
		case Keys::A:
			heroe->move(buffer->Graphics, 'A'); break;
		case Keys::D:
			heroe->move(buffer->Graphics, 'D'); break;
		case Keys::S:
			heroe->move(buffer->Graphics, 'S'); break;
		case Keys::W:
			heroe->move(buffer->Graphics, 'W'); break;
		case Keys::B: {
			if (heroe->getDirection() != 'S' && heroe->getDirection() != 'W') {
				if (controller->getcantbalas() > 0) {
					Proyectil* a = new Proyectil(heroe->getX(), heroe->getY(), bmpbala->Width, bmpbala->Height, heroe->getDirection());
					controller->addBala(a);
					controller->disminuircantbalas();
				}
			}
		}
		}
	}

	private: System::Void MyForm1_Load(System::Object^ sender, System::EventArgs^ e) {
	}
};
}