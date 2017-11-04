/*
 * Xournal++
 *
 * Base class for prviews in the sidebar
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "gui/sidebar/AbstractSidebarPage.h"
#include <XournalType.h>

#include <gtk/gtk.h>

#include <vector>

class PdfCache;
class SidebarLayout;
class SidebarPreviewBaseEntry;
class SidebarToolbar;

typedef std::vector<SidebarPreviewBaseEntry*> SidebarPreviewBaseEntryVector;

class SidebarPreviewBase : public AbstractSidebarPage
{
public:
<<<<<<< HEAD:src/gui/sidebar/previews/SidebarPreviews.h
	SidebarPreviews(Control* control, SidebarToolbar* toolbar);
	virtual ~SidebarPreviews();
=======
	SidebarPreviewBase(Control* control);
	virtual ~SidebarPreviewBase();
>>>>>>> upstream/master:src/gui/sidebar/previews/base/SidebarPreviewBase.h

public:

	/**
	 * Layout the pages to the current size of the sidebar
	 */
	void layout();

	/**
	 * Update the preview images
	 */
	virtual void updatePreviews() = 0;

	/**
	 * @overwrite
	 */
	virtual bool hasData();

	/**
	 * @overwrite
	 */
	virtual GtkWidget* getWidget();

	/**
	 * Setts the Background of the panel white, before the first draw
	 */
	void setBackgroundWhite();

	/**
	 * Gets the zoom factor for the previews
	 */
	double getZoom();

	/**
	 * Gets the PDF cache for preview rendering
	 */
	PdfCache* getCache();

public:
	// DocumentListener interface (only the part handled by SidebarPreviewBase)
	virtual void documentChanged(DocumentChangeType type);
	virtual void pageInserted(int page);
	virtual void pageDeleted(int page);

protected:
	/**
	 * Timeout callback to scroll to a page
	 */
	static bool scrollToPreview(SidebarPreviewBase* sidebar);

	/**
	 * The size of the sidebar has chnaged
	 */
	static void sizeChanged(GtkWidget* widget, GtkAllocation* allocation, SidebarPreviewBase* sidebar);

private:
	XOJ_TYPE_ATTRIB;

	/**
	 * The scrollbar with the icons
	 */
	GtkWidget* scrollPreview;

	/**
	 * The Table with the Toolbar and the Scrollbar
	 */
	GtkTable* table;

	/**
	 * The Zoom of the previews
	 */
	double zoom;

	/**
	 * Only once, see setBackgroundWhite()
	 */
	bool backgroundInitialized;

	/**
	 * For preview rendering
	 */
	PdfCache* cache;

	/**
	 * The layouting class for the prviews
	 */
	SidebarLayout* layoutmanager;


	// Members also used by subclasses
protected:

	/**
	 * The Toolbar to move, copy & delete pages
	 */
	SidebarToolbar* toolbar;

	/**
	 * The currently selected entry in the sidebar, starting from 0
	 * -1 means no valid selection
	 */
	size_t selectedEntry;

	/**
	 * The widget within the scrollarea with the page icons
	 */
	GtkWidget* iconViewPreview;

	/**
	 * The previews
	 */
	SidebarPreviewBaseEntryVector previews;

	friend class SidebarLayout;
};
