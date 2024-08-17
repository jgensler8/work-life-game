#pragma once
#include "includes.h"
#include "instant_message.h"

//! \brief various "widgets" used in the desktop bg
namespace widgets {
    //! \brief render im widget with online/offline status
    void render_im_widget();
    //! \brief render the night/day widget to show the passage of time
    void render_weather_widget(bool morning);
    //! \brief render a clendar on the right side the desktop showing days in the month (four week month)
    void render_calendar_widget();
    //! \brief render the weekly progress widget
    void render_weekly_progress_widget();
    //! \brief convenience wrapper for all desktop widgets
    void all(bool morning);
}