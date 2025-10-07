#pragma once

#include <QtWidgets/QDialog>
#include <QtWidgets/QButtonGroup>
#include <QtCore/QString>
#include <QtCore/QStringList>
#include "ui_SeerDebugDialog.h"

class OpenOCDSymbolWidgetManager;
class SeerDebugDialog : public QDialog, protected Ui::SeerDebugDialogForm {

    Q_OBJECT

    public:
        explicit SeerDebugDialog (QWidget* parent = 0);
       ~SeerDebugDialog ();

        // For any run mode.
        void                    setExecutableName                               (const QString& executableName);
        QString                 executableName                                  () const;

        void                    setExecutableSymbolName                         (const QString& executableSymbolName);
        QString                 executableSymbolName                            () const;

        void                    setExecutableWorkingDirectory                   (const QString& executableWorkingDirectory);
        QString                 executableWorkingDirectory                      () const;

        // Run or start executable. "run" or "start".
        void                    setExecutableArguments                          (const QString& executableArguments);
        QString                 executableArguments                             () const;
        void                    setBreakpointsFilename                          (const QString& breakpointsFilename);
        QString                 breakpointsFilename                             () const;
        void                    setBreakpointMode                               (const QString& mode);
        QString                 breakpointMode                                  () const;
        void                    setBreakpointFunctionName                       (const QString& nameoraddress);
        QString                 breakpointFunctionName                          () const;
        void                    setBreakpointSourceName                         (const QString& sourceFilenameAndLineno);
        QString                 breakpointSourceName                            () const;
        void                    setShowAssemblyTab                              (bool flag);
        bool                    showAssemblyTab                                 () const;
        void                    setRandomizeStartAddress                        (bool flag);
        bool                    randomizeStartAddress                           () const;
        void                    setNonStopMode                                  (bool flag);
        bool                    nonStopMode                                     () const;
        void                    setPreGdbCommands                               (const QStringList& preGdbCommands);
        QStringList             preGdbCommands                                  () const;
        void                    setPostGdbCommands                              (const QStringList& postGdbCommands);
        QStringList             postGdbCommands                                 () const;

        // Attach to a running process. "attach".
        void                    setAttachPid                                    (int pid);
        int                     attachPid                                       () const;

        // Connectect to a GDB server. "connect".
        void                    setConnectHostPort                              (const QString& connectHostPort);
        QString                 connectHostPort                                 () const;
        void                    setConnectRemoteTargetType                      (const QString& type);
        QString                 connectRemoteTargetType                         () const;
        void                    setConnectGdbserverDebug                        (bool enable);
        bool                    connectGdbserverDebug                           () const;


        // Connectect to a RR server. "rr".
        void                    setRRTraceDirectory                             (const QString& rrTraceDirectory);
        QString                 rrTraceDirectory                                () const;
        QString                 rrBreakpointsFilename                           () const;

        // Load a core file. "corefile".
        void                    setCoreFilename                                 (const QString& coreFilename);
        QString                 coreFilename                                    () const;

        // Get the launch mode.
        void                    setLaunchMode                                   (const QString& mode);
        QString                 launchMode                                      () const;

        // Get the project filename.
        void                    setProjectFilename                              (const QString& filename);
        QString                 projectFilename                                 () const;
        void                    loadProject                                     (const QString& filename, bool notify);

        // openocd get and set functions
        // ::Main
        const QString                       openOCDExePath                      ();
        void                                setOpenOCDExePath                   (const QString& path);
        const QString                       gdbPort                             ();
        void                                setGdbPort                          (const QString& port);
        const QString                       openOCDCommand                      ();
        void                                setOpenOCDCommand                   (const QString& command);
        const QString                       telnetPort                          ();
        void                                setTelnetPort                       (const QString& port);
        // ::GDB Multiarch
        const QString                       gdbMultiarchExePath                 ();
        void                                setGdbMultiarchExePath              (const QString& path);
        const QString                       gdbMultiarchCommand                 ();
        void                                setGdbMultiarchCommand              (const QString& command);
        bool                                isGdbMultiarchIsStopAtTempFunc      ();
        void                                setGdbMultiarchStopAtTempFunc       (bool check);
        const QString                       gdbMultiarchStopAtFunc              ();
        void                                setGdbMultiarchStopAtFunc           (const QString& func);
        bool                                isGdbMultiarchStopAtException       ();
        void                                setGdbMultiarchStopAtExeption       (bool check);
        const QString                       gdbMultiarchExeptionLevelToStop     ();
        void                                setGdbMultiarchExeptionLevelToStop  (const QString& level);
        const QString                       openOCDTarget                       ();
        void                                setOpenOCDTarget                    (const QString& target);
        // ::Docker
        bool                                isBuiltInDocker                     ();
        void                                setBuiltInDocker                    (bool check);
        const QString                       absoluteBuildFolderPath             ();
        void                                setAbsoluteBuildFolderPath          (const QString& path);
        const QString                       dockerBuildFolderPath               ();
        void                                setDockerBuildFolderPath            (const QString& path);
        // ::Symbol Files
        OpenOCDSymbolWidgetManager*         symbolWidgetManager                 ();
        void                                setSymbolFiles                      (const QMap<QString, QString>& symbolFiles);

    public slots:
        void                    handleExecutableNameToolButton                  ();
        void                    handleExecutableSymbolNameToolButton            ();
        void                    handleExecutableWorkingDirectoryToolButton      ();
        void                    handleLoadBreakpointsFilenameToolButton         ();
        void                    handleBreakpointInFunctionLineEdit              ();
        void                    handleLoadRRTraceDirectoryToolButton            ();
        void                    handleLoadCoreFilenameToolButton                ();
        void                    handleProgramPidToolButton                      ();
        void                    handleLoadProjectToolButton                     ();
        void                    handleSaveProjectToolButton                     ();
        void                    handleRunModeChanged                            (int id);

        // OpenOCD button handler
        void                    handleOpenOCDDefaultButtonClicked               ();
        void                    handleOpenOCDTabChanged                         (int id);
        void                    handleExecutableOpenOCDButtonClicked            ();
        void                    handleOpenOCDBuildFolderPathButton              ();

    private slots:
        void                    handleHelpModeToolButtonClicked                 ();
        void                    handleHelpRunToolButtonClicked                  ();
        void                    handleHelpAttachToolButtonClicked               ();
        void                    handleHelpConnectToolButtonClicked              ();
        void                    handleHelpRRToolButtonClicked                   ();
        void                    handleHelpCorefileToolButtonClicked             ();
        void                    handleOpenOCDDockerCheckboxClicked              ();
        void                    handleOpenOCDMainHelpButtonClicked              ();
        void                    handleOpenOCDTempFuncCheckBoxClicked            ();
        void                    handleOpenOCDStopExceptionLebelCheckBoxClicked  ();

    protected:
        void                    writeSettings                                   ();
        void                    readSettings                                    ();
        void                    resizeEvent                                     (QResizeEvent* event);

    private:
        QString                         _projectFilename;
        OpenOCDSymbolWidgetManager*     _OpenOCDSymbolWidgetManager = nullptr;
        QMap<QString, QString>          _symbolFiles;
};

class OpenOCDSymbolFileWidget: public QWidget{
    Q_OBJECT

public:
    explicit OpenOCDSymbolFileWidget (QWidget* parent = nullptr);
    ~OpenOCDSymbolFileWidget ();
    const QString               symbolPath ();
    const QString               sourcePath ();
    void                        setSymbolPath (const QString& path);
    void                        setSourcePath (const QString& path);


private slots:
    void                    handleOpenOCDSymbolPathButtonClicked ();
    void                    handleOpenOCDDirPathButtonClicked ();

private:
    QString                 _symbolPath;
    QString                 _sourcePath;
    QLineEdit*              _symbolLineEdit;
    QLineEdit*              _sourceLineEdit;
    QPushButton*            _symbolToolButton;
    QPushButton*            _sourceToolButton;
};

class OpenOCDSymbolWidgetManager : public QWidget{
    Q_OBJECT

public:
    explicit OpenOCDSymbolWidgetManager (QWidget* parent = nullptr);
    ~OpenOCDSymbolWidgetManager ();

    const QMap<QString, QString>    symbolFiles ();
    int                             countSymbolFiles ();
    void setSymbolPath (const QString& symbol, const QString& source);
    void                                    addGroupBox(const QString& symbolFile, const QString& sourceDir);

public slots:
    void                                    addEmptyGroupBox();
    void                                    deleteGroupBox();

private:
    int                                     _countSymbolFiles = 0;
    QWidget *                               _scrollWidget;
    QVBoxLayout *                           _scrollLayout;
    QList<OpenOCDSymbolFileWidget *>        _groupBoxes;
    QMap<QString, QString>                  _symbolFiles;
};