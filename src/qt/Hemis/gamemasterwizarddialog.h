// Copyright (c) 2019-2022 The Hemis Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef GAMEMASTERWIZARDDIALOG_H
#define GAMEMASTERWIZARDDIALOG_H

#include "qt/Hemis/focuseddialog.h"
#include "qt/Hemis/snackbar.h"
#include "gamemasterconfig.h"
#include "qt/Hemis/pwidget.h"

class GMModel;
class WalletModel;

namespace Ui {
class GameMasterWizardDialog;
class QPushButton;
}

class GameMasterWizardDialog : public FocusedDialog, public PWidget::Translator
{
    Q_OBJECT

public:
    explicit GameMasterWizardDialog(WalletModel* walletMode,
                                    GMModel* gmModel,
                                    QWidget *parent = nullptr);
    ~GameMasterWizardDialog() override;
    void showEvent(QShowEvent *event) override;
    QString translate(const char *msg) override { return tr(msg); }

    QString returnStr = "";
    bool isOk = false;
    CGamemasterConfig::CGamemasterEntry* gmEntry = nullptr;

private Q_SLOTS:
    void accept() override;
    void onBackClicked();
private:
    Ui::GameMasterWizardDialog *ui;
    QPushButton* icConfirm1;
    QPushButton* icConfirm3;
    QPushButton* icConfirm4;
    SnackBar *snackBar = nullptr;
    int pos = 0;

    WalletModel* walletModel{nullptr};
    GMModel* gmModel{nullptr};
    bool createGM();
    void inform(const QString& text);
};

#endif // GAMEMASTERWIZARDDIALOG_H
