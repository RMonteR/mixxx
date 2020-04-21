#ifndef PREFERENCES_BEATDETECTIONSETTINGS_H
#define PREFERENCES_BEATDETECTIONSETTINGS_H

#include "preferences/usersettings.h"

#define VAMP_CONFIG_KEY "[Vamp]"

// VAMP_CONFIG_KEY Preferences. WARNING: Do not fix the "analyser" spelling here
// since user config files contain these.
#define VAMP_ANALYZER_BEAT_LIBRARY "AnalyserBeatLibrary"
#define VAMP_ANALYZER_BEAT_PLUGIN_ID "AnalyserBeatPluginID"

#define BPM_CONFIG_KEY "[BPM]"

// BPM_CONFIG_KEY Preferences
#define BPM_DETECTION_ENABLED "BPMDetectionEnabled"
#define BPM_FIXED_TEMPO_ASSUMPTION "BeatDetectionFixedTempoAssumption"
#define BPM_FIXED_TEMPO_OFFSET_CORRECTION "FixedTempoOffsetCorrection"
#define BPM_REANALYZE_WHEN_SETTINGS_CHANGE "ReanalyzeWhenSettingsChange"
#define BPM_FAST_ANALYSIS_ENABLED "FastAnalysisEnabled"

#define BPM_RANGE_START "BPMRangeStart"
#define BPM_RANGE_END "BPMRangeEnd"

class BeatDetectionSettings {
  public:
    BeatDetectionSettings(UserSettingsPointer pConfig) : m_pConfig(pConfig) {}

    DEFINE_PREFERENCE_HELPERS(BpmDetectionEnabled, bool,
                              BPM_CONFIG_KEY, BPM_DETECTION_ENABLED, true);

    DEFINE_PREFERENCE_HELPERS(BpmRangeStart, int, BPM_CONFIG_KEY, BPM_RANGE_START, 70);

    DEFINE_PREFERENCE_HELPERS(BpmRangeEnd, int, BPM_CONFIG_KEY, BPM_RANGE_END, 140);

    DEFINE_PREFERENCE_HELPERS(FixedTempoAssumption, bool,
                              BPM_CONFIG_KEY, BPM_FIXED_TEMPO_ASSUMPTION, true);

    DEFINE_PREFERENCE_HELPERS(FixedTempoOffsetCorrection, bool,
                              BPM_CONFIG_KEY, BPM_FIXED_TEMPO_OFFSET_CORRECTION, true);

    DEFINE_PREFERENCE_HELPERS(ReanalyzeWhenSettingsChange, bool,
                              BPM_CONFIG_KEY, BPM_REANALYZE_WHEN_SETTINGS_CHANGE, false);

    DEFINE_PREFERENCE_HELPERS(FastAnalysis, bool,
                              BPM_CONFIG_KEY, BPM_FAST_ANALYSIS_ENABLED, false);

    QString getBeatPluginId() const {
        return m_pConfig->getValue<QString>(ConfigKey(
                VAMP_CONFIG_KEY, VAMP_ANALYZER_BEAT_PLUGIN_ID));
    }
    void setBeatPluginId(const QString& plugin_id) {
        m_pConfig->setValue(
                ConfigKey(VAMP_CONFIG_KEY, VAMP_ANALYZER_BEAT_PLUGIN_ID),
                plugin_id);
    }

  private:
    UserSettingsPointer m_pConfig;
};

#endif /* PREFERENCES_BEATDETECTIONSETTINGS_H */
