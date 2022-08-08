// Copyright (c) the JPEG XL Project Authors.
//
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file or at
// https://developers.google.com/open-source/licenses/bsd

#ifndef TOOLS_COMPARISON_VIEWER_SETTINGS_H_
#define TOOLS_COMPARISON_VIEWER_SETTINGS_H_

#include <QDialog>
#include <QSettings>

#include "tools/comparison_viewer/split_image_renderer.h"
#include "tools/comparison_viewer/ui_settings.h"

namespace jxl {

class SettingsDialog : public QDialog {
  Q_OBJECT

 public:
  explicit SettingsDialog(QWidget* parent = nullptr);
  ~SettingsDialog() override = default;

  SplitImageRenderingSettings renderingSettings() const;

 private slots:
  void on_SettingsDialog_accepted();
  void on_SettingsDialog_rejected();

 private:
  void settingsToUi();

  Ui::SettingsDialog ui_;
  QSettings settings_;
  SplitImageRenderingSettings renderingSettings_;
};

}  // namespace jxl

#endif  // TOOLS_COMPARISON_VIEWER_SETTINGS_H_
