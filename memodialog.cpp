#include "memodialog.h"
#include "ui_memodialog.h"
#include <QDebug>

MemoDialog::MemoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoDialog)
{
    ui->setupUi(this);
}

MemoDialog::MemoDialog(const QByteArray &t, QWidget *parent)
    : MemoDialog (parent)
{
    setText(t);
}

MemoDialog::~MemoDialog()
{
    delete ui;
}

QByteArray MemoDialog::text()
{
    return m_text;
}

void MemoDialog::setText(const QByteArray &s)
{
    m_text = s;
    ui->textEdit->setPlainText(m_text);
}

void MemoDialog::on_buttonBox_accepted()
{
    setText(ui->textEdit->toPlainText().toUtf8());
}
