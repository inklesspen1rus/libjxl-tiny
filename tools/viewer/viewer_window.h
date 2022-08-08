// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef TOOLS_VIEWER_VIEWER_WINDOW_H_
#define TOOLS_VIEWER_VIEWER_WINDOW_H_

#include <QByteArray>
#include <QMainWindow>
#include <QStringList>

#include "tools/viewer/ui_viewer_window.h"

namespace jxl {

class ViewerWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit ViewerWindow(QWidget* parent = nullptr);

 public slots:
  void loadFilesAndDirectories(QStringList entries);

 private slots:
  void on_actionOpen_triggered();
  void on_actionPreviousImage_triggered();
  void on_actionNextImage_triggered();
  void refreshImage();

 private:
  const QByteArray monitorProfile_;
  Ui::ViewerWindow ui_;
  QStringList filenames_;
  int currentFileIndex_ = 0;
  bool hasWarnedAboutMonitorProfile_ = false;
};

}  // namespace jxl

#endif  // TOOLS_VIEWER_VIEWER_WINDOW_H_
