#ifndef PATHOLOGYWORKSTATION_H
#define PATHOLOGYWORKSTATION_H

#include <QMainWindow>
#include <QDir>
#include <QStringList>
#include <memory>

class MultiResolutionImage;
class QHBoxLayout;
class QAction;
class QStatusBar;
class QMenuBar;
class PathologyViewer;
class WorkstationExtensionPluginInterface;
class QActionGroup;
class QSettings;

class PathologyWorkstation : public QMainWindow
{
  Q_OBJECT

public:
  explicit PathologyWorkstation(QWidget* parent = 0);
  ~PathologyWorkstation();

  void setCacheSize(const unsigned long long& cacheMaxByteSize);

  unsigned long long getCacheSize() const;

signals:
  void newImageLoaded(MultiResolutionImage*, std::string);
  void imageClosed();

private slots:
  void on_actionClose_triggered();
  void on_actionOpen_triggered();

private:
  MultiResolutionImage *_img;
  unsigned long long _cacheMaxByteSize;
  QSettings* _settings;
  
  // Plugins
  QDir _pluginsDir;
  std::vector<std::string> _extensionPluginFileNames;
  std::vector<std::string> _toolPluginFileNames;

  // GUI object
  QAction *actionOpen;
  QAction *actionClose;
  QActionGroup *_toolActions;
  QWidget *centralWidget;
  QHBoxLayout *horizontalLayout_2;
  PathologyViewer *pathologyView;
  QMenuBar *menuBar;
  QMenu *menuFile;
  QMenu *menuView;
  QToolBar *mainToolBar;
  QStatusBar *statusBar;

  // Initialize the GUI
  void initializeDocks();
  void setupUi();
  void retranslateUi();
  void loadPlugins();
  void readSettings();
  void writeSettings();

  std::vector<std::unique_ptr<WorkstationExtensionPluginInterface> > _extensions;
};

#endif // PATHOLOGYWORKSTATION_H
