#ifndef __ASAP_GUI_WORKLISTDATAACQUISITIONINTERFACE__
#define __ASAP_GUI_WORKLISTDATAACQUISITIONINTERFACE__

#include <deque>
#include <memory>
#include <mutex>
#include <unordered_map>
#include <QtWidgets/QMainWindow>
#include <QStandardItemModel>

#include "CompositeChild.h"
#include "ui_WorklistWindowLayout.h"
#include "Data/WorklistDataAcquisitionInterface.h"
#include "Misc/TemporaryDirectoryTracker.h"
#include "ASAP/ASAP_Window.h"

namespace ASAP::GUI
{
	struct WorklistWindowSettings
	{
		std::string				source_location;
		std::deque<std::string>	previous_sources;
	};

	class WorklistWindow : public CompositeChild // public QMainWindow,
	{
		Q_OBJECT

		public:
			explicit WorklistWindow(QWidget* parent = 0);
			~WorklistWindow(void);

			void AttachWorkstation(ASAP_Window& workstation, const int tab_id);
			WorklistWindowSettings GetStandardSettings(void);

			void SetDataSource(const std::string source_path, const std::unordered_map<std::string, std::string> additional_params);
			void SetWorklistItems(const Data::DataTable& items, QStandardItemModel* model);
			void SetPatientsItems(const Data::DataTable& items, QStandardItemModel* model);
			void SetStudyItems(const Data::DataTable& items, QStandardItemModel* model);
			void SetImageItems(const Data::DataTable& items, QStandardItemModel* model);

		public slots:
			void MoveImageSelectionLeft(void);
			void MoveImageSelectionRight(void);
			void UpdateImageIcons(void);
			void UpdateStatusBar(const QString& message);

		private:
			std::unique_ptr<Data::WorklistDataAcquisitionInterface>	m_data_acquisition_;
			std::unique_ptr<Ui::WorklistWindowLayout>				m_ui_;
			WorklistWindowSettings									m_settings_;
			bool													m_stop_loading_; // Todo: Refactor into something cleaner
			std::mutex												m_image_loading_access_; // Todo: Refactor into something cleaner
			std::mutex												m_image_switch_access_;
			Misc::TemporaryDirectoryTracker							m_storage_directory_;
			std::vector<std::unique_ptr<QAction>>					m_history_actions_;
			ASAP_Window*											m_workstation_; // Todo: Clean up or perhaps combine in struct
			int														m_workstation_tab_id_;

			QStandardItemModel* m_images_model_;
			QStandardItemModel* m_patients_model_;
			QStandardItemModel* m_studies_model_;
			QStandardItemModel* m_worklist_model_;

			bool CheckSchema_(Data::WorklistDataAcquisitionInterface* source);
			void LoadSettings_(void);
			void StoreSettings_(void);
			void StopThumbnailLoading_(void);
			void UpdatePreviousSources_(void);
			void UpdateSourceViews_(void);

			void SetHeaders_(const std::set<std::string> headers, QStandardItemModel* model, QAbstractItemView* view);
			void SetModels_(void);
			void SetSlots_(void);

		private slots:
			void OnWorklistClear_(QModelIndex index, int row, int column);
			void OnPatientsClear_(QModelIndex index, int row, int column);
			void OnStudyClear_(QModelIndex index, int row, int column);

			void OnWorklistSelect_(QModelIndex index);
			void OnPatientSelect_(QModelIndex index);
			void OnStudySelect_(QModelIndex index);
			void OnImageSelect_(QModelIndex index);

			void OnSelectFileSource_(bool checked);
			void OnSelectFolderSource_(bool checked);
			void OnSelectExternalSource_(bool checked);
	};
}
#endif // __ASAP_GUI_WORKLISTDATAACQUISITIONINTERFACE__