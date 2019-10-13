#include <stdio.h>
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <libxml/tree.h>
#include <libxml/HTMLparser.h>
#include <msclr\marshal_cppstd.h>

using namespace std;
int Writer(char *data, size_t size, size_t nmemb, string *answer);
void RequestToServer(const string &link,string &answer);
bool CreateDomFromHtml(std::string filename, std::string &html);

void RequestToServer(const string &link,string &answer) {
		std::string url = "https://";
		url.append(link);
		CURL *curl;
		CURLcode result;
		curl = curl_easy_init();
		if (curl) {
			curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, FALSE);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Writer);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &answer);
			result = curl_easy_perform(curl);
			curl_easy_cleanup(curl);
		}
	}
int Writer(char *data, size_t size, size_t nmemb, string *answer)	{
		int result = 0;
		if (answer != NULL) {
			 answer->append(data, size * nmemb);
			 result = size * nmemb;
		 }
		return result;
	}
bool CreateDomFromHtml(std::string filename, std::string &html) {
		bool result = true;
		xmlDoc* dom_tree = htmlReadDoc((xmlChar*)html.c_str(), NULL, NULL, HTML_PARSE_RECOVER | HTML_PARSE_NOERROR | HTML_PARSE_NOWARNING);
		if (xmlSaveFormatFileEnc(filename.c_str(), dom_tree, "UTF-8", 1) == -1) {
			result = false;
		}
		xmlFreeDoc(dom_tree);
		return result;
	}
#pragma once
namespace parser_with_ui {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  b_create;
	private: System::Windows::Forms::Button^  b_close;
	private: System::Windows::Forms::Label^  l_link;
	private: System::Windows::Forms::Label^  l_filename;
	private: System::Windows::Forms::TextBox^  tb_link;
	private: System::Windows::Forms::TextBox^  tb_filename;


	protected: 

	protected: 

	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->b_create = (gcnew System::Windows::Forms::Button());
			this->b_close = (gcnew System::Windows::Forms::Button());
			this->l_link = (gcnew System::Windows::Forms::Label());
			this->l_filename = (gcnew System::Windows::Forms::Label());
			this->tb_link = (gcnew System::Windows::Forms::TextBox());
			this->tb_filename = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// b_create
			// 
			this->b_create->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(76)), 
				static_cast<System::Int32>(static_cast<System::Byte>(162)));
			this->b_create->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->b_create->Location = System::Drawing::Point(51, 279);
			this->b_create->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->b_create->Name = L"b_create";
			this->b_create->Size = System::Drawing::Size(113, 57);
			this->b_create->TabIndex = 0;
			this->b_create->Text = L"Create DOM";
			this->b_create->UseVisualStyleBackColor = false;
			this->b_create->Click += gcnew System::EventHandler(this, &Form1::b_create_Click);
			// 
			// b_close
			// 
			this->b_close->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(76)), 
				static_cast<System::Int32>(static_cast<System::Byte>(162)));
			this->b_close->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->b_close->Location = System::Drawing::Point(473, 279);
			this->b_close->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->b_close->Name = L"b_close";
			this->b_close->Size = System::Drawing::Size(110, 57);
			this->b_close->TabIndex = 1;
			this->b_close->Text = L"Close";
			this->b_close->UseVisualStyleBackColor = false;
			this->b_close->Click += gcnew System::EventHandler(this, &Form1::b_close_Click);
			// 
			// l_link
			// 
			this->l_link->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->l_link->AutoSize = true;
			this->l_link->Font = (gcnew System::Drawing::Font(L"Segoe Print", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->l_link->Location = System::Drawing::Point(104, 13);
			this->l_link->Name = L"l_link";
			this->l_link->Size = System::Drawing::Size(401, 26);
			this->l_link->TabIndex = 2;
			this->l_link->Text = L"Please enter a link to page (e.g. www.google.com/):";
			// 
			// l_filename
			// 
			this->l_filename->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom) 
				| System::Windows::Forms::AnchorStyles::Left) 
				| System::Windows::Forms::AnchorStyles::Right));
			this->l_filename->AutoSize = true;
			this->l_filename->Font = (gcnew System::Drawing::Font(L"Segoe Print", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->l_filename->Location = System::Drawing::Point(46, 136);
			this->l_filename->Name = L"l_filename";
			this->l_filename->Size = System::Drawing::Size(537, 26);
			this->l_filename->TabIndex = 3;
			this->l_filename->Text = L"Please enter a filename where you will save your dom (e.g. dom.xml):";
			this->l_filename->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// tb_link
			// 
			this->tb_link->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->tb_link->Location = System::Drawing::Point(109, 70);
			this->tb_link->Name = L"tb_link";
			this->tb_link->Size = System::Drawing::Size(396, 30);
			this->tb_link->TabIndex = 4;
			// 
			// tb_filename
			// 
			this->tb_filename->Font = (gcnew System::Drawing::Font(L"Segoe Print", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->tb_filename->Location = System::Drawing::Point(109, 182);
			this->tb_filename->Name = L"tb_filename";
			this->tb_filename->Size = System::Drawing::Size(396, 30);
			this->tb_filename->TabIndex = 5;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(129)), static_cast<System::Int32>(static_cast<System::Byte>(134)), 
				static_cast<System::Int32>(static_cast<System::Byte>(213)));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(627, 360);
			this->Controls->Add(this->tb_filename);
			this->Controls->Add(this->tb_link);
			this->Controls->Add(this->l_filename);
			this->Controls->Add(this->l_link);
			this->Controls->Add(this->b_close);
			this->Controls->Add(this->b_create);
			this->Font = (gcnew System::Drawing::Font(L"Segoe Print", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)), 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->ForeColor = System::Drawing::SystemColors::Info;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"Form1";
			this->Text = L"Parser";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	
	private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void b_close_Click(System::Object^  sender, System::EventArgs^  e) {
				 Application::Exit();
			 }
	private: System::Void b_create_Click(System::Object^  sender, System::EventArgs^  e) {
				std::string link = msclr::interop::marshal_as<std::string>(tb_link->Text);
				std::string filename = msclr::interop::marshal_as<std::string>(tb_filename->Text);
				std::string html;
				RequestToServer(link,html);
				bool result = CreateDomFromHtml(filename,html);
				if(result){
				   MessageBox::Show("File was created.", "", MessageBoxButtons::OK, MessageBoxIcon::None);
				} else{
				  MessageBox::Show("File wasn't created.", "", MessageBoxButtons::OK, MessageBoxIcon::None);
				}
			 }
};
}

