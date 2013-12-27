//
//  Util.cpp
//  Testing
//
//  Created by Calvin Phung on 8/27/13.
//
//

#include "Util.h"

#include <vector>
#include <cstdlib>
#include <sstream>
#include <iomanip>

Util::ConfigGlobal::ConfigGlobal()
{
    const float SESSION_TIME = 1500.0;
    const float STAGE_TIME = 90.0;
    const int STAGE_TOTAL_SIGNALS = 60;
    const int STAGE_TOTAL_TARGETS = 20;
    const int STAGE_TOTAL_TARGETS_VARIANCE = 2;
    const float STAGE_PROFICIENCY_THRESHOLD1 = 0.6; // Where on bar is indicator in %
    const float STAGE_PROFICIENCY_THRESHOLD2 = 0.8;
    const float STAGE_PROFICIENCY_THRESHOLD3 = 0.95;
    const int STAGE_TIME_THRESHOLD1 = 40; // How many signals passed of stage for this star disregarding initial signals
    const int STAGE_TIME_THRESHOLD2 = 50;
    const int STAGE_TIME_THRESHOLD3 = 55;
    const int STAGE_NAVIGATION_THRESHOLD1 = 20; // How many items gathered before dying
    const int STAGE_NAVIGATION_THRESHOLD2 = 25;
    const int STAGE_NAVIGATION_THRESHOLD3 = 30;
    
    const Vector3 TUNNEL_REFERENCE_FORWARD = Vector3(0, 0, -1);
    const Vector3 TUNNEL_REFERENCE_UPWARD = Vector3(0, 1, 0);
    const Vector3 TUNNEL_REFERENCE_RIGHT = Vector3(1, 0, 0);
    const int TUNNEL_MIN_ANGLE_TURN = 0; //Configurable
    const int TUNNEL_MAX_ANGLE_TURN = 3; //Configurable
    const float TUNNEL_SEGMENT_WIDTH = 25.0; //Configurable
    const float TUNNEL_SEGMENT_DEPTH = 25.0; //Configurable
    const float TUNNEL_SEGMENT_BUFFER = 25;
    const float TUNNEL_WALL_LENGTH = TUNNEL_SEGMENT_WIDTH / (2 * Math::Cos(Ogre::Radian(Math::PI) / 4) + 1);
    const int TUNNEL_SEGMENTS_PER_SECTION = 5;
    const int TUNNEL_SEGMENTS_PER_POD = 4;
    const int TUNNEL_SEGMENTS_PER_DISTRACTORS = 4;
    const int TUNNEL_SEGMENTS_BEFORE_REFRESH = TUNNEL_SEGMENTS_PER_SECTION * 2;
    const int INITIAL_SEGMENTS_FIRST_POD = 0;
    const int INITIAL_SEGMENTS_FIRST_DISTRACTORS = -2;
    const int INITIATION_SECTIONS = 1;
    const float VINE_T_OFFSET = 1.5;
    const float VINE_RADIUS = TUNNEL_SEGMENT_WIDTH / 15;
    const float VINE_TRANSITION_SPEED = 5.0;
    const int POD_APPEARANCE = 2;
    const float POD_HEAD_RADIUS = TUNNEL_SEGMENT_WIDTH / 25;
    const float POD_STEM_RADIUS = TUNNEL_SEGMENT_WIDTH / 100;
    const float POD_STEM_LENGTH = TUNNEL_WALL_LENGTH / 2;
    const float POD_ROTATE_SPEED = 5.0;
    const int POD_BIN_SIZE = 9;
    const int POD_NBACK_CHANCE = 33;
    const int STAGE_TOTAL_DISTRACTORS_MIN = 1;
    const int STAGE_TOTAL_DISTRACTORS_MAX = 1;
    const float SEAT_LENGTH = POD_HEAD_RADIUS * 2;
    
    const int TUNNEL_SECTIONS = 5;
    const int NBACK = 2; //Configurable
    const int CONTROL = 1; //Configurable
    const int HISTORY_MODE = -1; //Confiugrable
    
    const int STARTING_HP = 3;
    const int HP_NEGATIVE_LIMIT = 0;
    const int HP_POSITIVE_LIMIT = 1;
    const int HP_NEGATIVE_CORRECT_ANSWER = 0;
    const int HP_NEGATIVE_WRONG_ANSWER = -1;
    const int HP_POSITIVE_CORRECT_ANSWER = 0;
    const int HP_POSITIVE_WRONG_ANSWER = -1;
    const float DRAIN_SPEED = 2;
    const float INIT_CAM_SPEED = 15.0;
    const float STARTUP_CAM_SPEED = 60.0;
    const float MODIFIER_CAM_SPEED = 5.0;
    const float MIN_CAM_SPEED = 5.0;
    const float MAX_CAM_SPEED = 25.0;
    const float NLEVEL_SPEED_MODIFIER = 0.8;
    
    const int NUM_TO_SPEED_UP = 3;
    const int NUM_TO_SPEED_DOWN = 1;
    const float STEPSIZE_SPEED_UP = 3.0;
    const float STEPSIZE_SPEED_DOWN = -3.0;
    
    const float HP_BAR_XREF = 0.05;
    const float HP_BAR_YREF = 0.05;
    const float HP_BAR_WIDTH = 0.9;
    const float HP_BAR_HEIGHT = 0.05;
    
    const int SCREEN_WIDTH = 1024;
    const int SCREEN_HEIGHT = 800;
    
    const float TIMED_RUN_CONTROL_UP_DIST1 = 3000.0;
    const float TIMED_RUN_CONTROL_UP_DIST2 = 7500.0;
    const float TIMED_RUN_CONTROL_UP_DIST3 = 20000.0;
    const int TIMED_RUN_NMAX = 5;
    
    const float SWIPE_SENSITIVITY = 12.0;
    const int SWIPE_INVERTED = 0;
    
    sessionTime = SESSION_TIME;
    stageTime = STAGE_TIME;
    stageTotalSignals = STAGE_TOTAL_SIGNALS;
    stageTotalTargets = STAGE_TOTAL_TARGETS;
    stageTotalTargetsVariance = STAGE_TOTAL_TARGETS_VARIANCE;
    stageProficiencyThreshold1 = STAGE_PROFICIENCY_THRESHOLD1;
    stageProficiencyThreshold2 = STAGE_PROFICIENCY_THRESHOLD2;
    stageProficiencyThreshold3 = STAGE_PROFICIENCY_THRESHOLD3;
    stageTimeThreshold1 = STAGE_TIME_THRESHOLD1;
    stageTimeThreshold2 = STAGE_TIME_THRESHOLD2;
    stageTimeThreshold3 = STAGE_TIME_THRESHOLD3;
    stageNavigationThreshold1 = STAGE_NAVIGATION_THRESHOLD1;
    stageNavigationThreshold2 = STAGE_NAVIGATION_THRESHOLD2;
    stageNavigationThreshold3 = STAGE_NAVIGATION_THRESHOLD3;
    gameMode = 1;
    revealColor = 1;
    revealSound = 1;
    revealShape = 1;
    tunnelReferenceForward = TUNNEL_REFERENCE_FORWARD;
    tunnelReferenceUpward = TUNNEL_REFERENCE_UPWARD;
    tunnelReferenceRight = TUNNEL_REFERENCE_RIGHT;
    tunnelMinAngleTurn = TUNNEL_MIN_ANGLE_TURN;
    tunnelMaxAngleTurn = TUNNEL_MAX_ANGLE_TURN;
    tunnelSegmentWidth = TUNNEL_SEGMENT_WIDTH;
    tunnelSegmentDepth = TUNNEL_SEGMENT_DEPTH;
    tunnelSegmentBuffer = TUNNEL_SEGMENT_BUFFER;
    tunnelWallLength = TUNNEL_WALL_LENGTH;
    tunnelSegmentsPerSection = TUNNEL_SEGMENTS_PER_SECTION;
    tunnelSegmentsPerPod = TUNNEL_SEGMENTS_PER_POD;
    tunnelSegmentsPerDistractors = TUNNEL_SEGMENTS_PER_DISTRACTORS;
    tunnelSegmentsBeforeRefresh = TUNNEL_SEGMENTS_BEFORE_REFRESH;
    initialSegmentsFirstPod = INITIAL_SEGMENTS_FIRST_POD;
    initialSegmentsFirstDistractors = INITIAL_SEGMENTS_FIRST_DISTRACTORS;
    initiationSections = INITIATION_SECTIONS;
    vineTOffset = VINE_T_OFFSET;
    vineRadius = VINE_RADIUS;
    vineTransitionSpeed = VINE_TRANSITION_SPEED;
    podAppearance = POD_APPEARANCE;
    podHeadRadius = POD_HEAD_RADIUS;
    podStemRadius = POD_STEM_RADIUS;
    podStemLength = POD_STEM_LENGTH;
    podRotateSpeed = POD_ROTATE_SPEED;
    podBinSize = POD_BIN_SIZE;
    podNBackChance = POD_NBACK_CHANCE;
    stageTotalDistractorsMin = STAGE_TOTAL_DISTRACTORS_MIN;
    stageTotalDistractorsMax = STAGE_TOTAL_DISTRACTORS_MAX;
    seatLength = SEAT_LENGTH;
    tunnelSections = TUNNEL_SECTIONS;
    nback = NBACK;
    control = CONTROL;
    historyMode = HISTORY_MODE;
    startingHP = STARTING_HP;
    HPNegativeLimit = HP_NEGATIVE_LIMIT;
    HPPositiveLimit = HP_POSITIVE_LIMIT;
    HPNegativeCorrectAnswer = HP_NEGATIVE_CORRECT_ANSWER;
    HPNegativeWrongAnswer = HP_NEGATIVE_WRONG_ANSWER;
    HPPositiveCorrectAnswer = HP_POSITIVE_CORRECT_ANSWER;
    HPPositiveWrongAnswer = HP_POSITIVE_WRONG_ANSWER;
    initCamSpeed = INIT_CAM_SPEED;
    startupCamSpeed = STARTUP_CAM_SPEED;
    modifierCamSpeed = MODIFIER_CAM_SPEED;
    minCamSpeed = MIN_CAM_SPEED;
    maxCamSpeed = MAX_CAM_SPEED;
    nlevelSpeedModifier = NLEVEL_SPEED_MODIFIER;
    numToSpeedUp = NUM_TO_SPEED_UP;
    numToSpeedDown = NUM_TO_SPEED_DOWN;
    stepsizeSpeedUp = STEPSIZE_SPEED_UP;
    stepsizeSpeedDown = STEPSIZE_SPEED_DOWN;
    HPBarXRef = HP_BAR_XREF;
    HPBarYRef = HP_BAR_YREF;
    HPBarWidth = HP_BAR_WIDTH;
    HPBarHeight = HP_BAR_HEIGHT;
    screenWidth = SCREEN_WIDTH;
    screenHeight = SCREEN_HEIGHT;
    timedRunControlUpDist1 = TIMED_RUN_CONTROL_UP_DIST1;
    timedRunControlUpDist2 = TIMED_RUN_CONTROL_UP_DIST2;
    timedRunControlUpDist3 = TIMED_RUN_CONTROL_UP_DIST3;
    timedRunNMax = TIMED_RUN_NMAX;
    swipeSensitivity = SWIPE_SENSITIVITY;
    swipeInverted = SWIPE_INVERTED;
}

// Updates variables that depend on other globals, should call this if a game global has changed
void Util::ConfigGlobal::set()
{
    viewportMainWidth_modeRight = screenWidth - 224;
    viewportMainHeight_modeRight = screenHeight;
    viewportSideWidth_modeRight = 224;
    viewportSideHeight_modeRight = screenHeight;
    
    viewportMainWidth_modeBottom = screenWidth;
    viewportMainHeight_modeBottom = screenHeight - 100;
    viewportSideWidth_modeBottom = screenWidth;
    viewportSideHeight_modeBottom = 100;
    
    viewportMainWidth_modeNone = screenWidth;
    viewportMainHeight_modeNone = screenHeight;
    viewportSideWidth_modeNone = 0;
    viewportSideHeight_modeNone = 0;
    
    label1_posX = screenWidth / 2;
    label1_posY = 3 * screenHeight / 40;
    label2_posX = screenWidth / 80;
    label2_posY = 7 * screenHeight / 40;
    label3_posX = screenWidth - screenWidth / 40;
    label3_posY = 5 * screenHeight / 40;
    label4_posX = screenWidth / 80;
    label4_posY = 5 * screenHeight / 40;
    label5_posX = screenWidth - screenWidth / 40;
    label5_posY = 7 * screenHeight / 40;
    label6_posX = screenWidth / 2;
    label6_posY = screenHeight / 2;
}

void Util::ConfigGlobal::initPaths(const char* name)
{
    playerName = name;
    
#if defined(OGRE_IS_IOS)
    savePath = Util::getIOSDir() + "/" + playerName + "/" + playerName + ".save";
    configPath = Util::getIOSDir() + "/" + playerName + "/" + playerName + ".conf";
    configBackup = Util::getIOSDir() + "/backup.conf";
#else
    savePath = Util::getOSXDir() + "/" + playerName + "/" + playerName + ".save";
    configPath = Util::getOSXDir() + "/" + playerName + "/" + playerName + ".conf";
    configBackup = Util::getOSXDir() + "/backup.conf";
#endif
    
    //Build log path
    logPath = buildLogPath(playerName);
    
    bool saveGood = loadSaveFile(savePath);
    if (!saveGood)
        std::cout << "WARNING: Save File could not be loaded correctly" << std::endl;
    
    bool configGood = loadConfig(currStageID);
    if (!configGood)
    {
        std::cout << "WARNING: Config File could not be loaded correctly" << std::endl;
        setMessage("WARNING: Failed to read configuration", MESSAGE_ERROR);
    }
    
}

void Util::ConfigGlobal::setConfigValue(std::istream& in, std::string paramName)
{
    if (paramName == "stageID")
        in >> stageID;
    else if (paramName == "sessionTime")
        in >> sessionTime;
    else if (paramName == "stageTime")
        in >> stageTime;
    else if (paramName == "stageTotalSignals")
        in >> stageTotalSignals;
    else if (paramName == "stageTotalTargets")
        in >> stageTotalTargets;
    else if (paramName == "stageTotalTargetsVariance")
        in >> stageTotalTargetsVariance;
    else if (paramName == "nback")
        in >> nback;
    else if (paramName == "control")
        in >> control;
    else if (paramName == "gameMode")
        in >> gameMode;
    else if (paramName == "revealColor")
        in >> revealColor;
    else if (paramName == "revealSound")
        in >> revealSound;
    else if (paramName == "revealShape")
        in >> revealShape;
    else if (paramName == "tunnelMinAngleTurn")
        in >> tunnelMinAngleTurn;
    else if (paramName == "tunnelMaxAngleTurn")
        in >> tunnelMaxAngleTurn;
    else if (paramName == "tunnelSegmentsPerSection")
        in >> tunnelSegmentsPerSection;
    else if (paramName == "tunnelSegmentsPerPod")
        in >> tunnelSegmentsPerPod;
    else if (paramName == "tunnelSegmentsPerDistractors")
        in >> tunnelSegmentsPerDistractors;
    else if (paramName == "podRotateSpeed")
        in >> podRotateSpeed;
    else if (paramName == "podAppearance")
        in >> podAppearance;
    else if (paramName == "podBinSize")
        in >> podBinSize;
    else if (paramName == "podNBackChance")
        in >> podNBackChance;
    else if (paramName == "stageTotalDistractorsMin")
        in >> stageTotalDistractorsMin;
    else if (paramName == "stageTotalDistractorsMax")
        in >> stageTotalDistractorsMax;
    else if (paramName == "HPNegativeLimit")
        in >> HPNegativeLimit;
    else if (paramName == "HPPositiveLimit")
        in >> HPPositiveLimit;
    else if (paramName == "HPPositiveCorrectAnswer")
        in >> HPPositiveCorrectAnswer;
    else if (paramName == "HPPositiveWrongAnswer")
        in >> HPPositiveWrongAnswer;
    else if (paramName == "HPNegativeCorrectAnswer")
        in >> HPNegativeCorrectAnswer;
    else if (paramName == "HPNegativeWrongAnswer")
        in >> HPNegativeWrongAnswer;
    else if (paramName == "initCamSpeed")
        in >> initCamSpeed;
    else if (paramName == "modifierCamSpeed")
        in >> modifierCamSpeed;
    else if (paramName == "minCamSpeed")
        in >> minCamSpeed;
    else if (paramName == "maxCamSpeed")
        in >> maxCamSpeed;
    else if (paramName == "nlevelSpeedModifier")
        in >> nlevelSpeedModifier;
    else if (paramName == "numToSpeedUp")
        in >> numToSpeedUp;
    else if (paramName == "numToSpeedDown")
        in >> numToSpeedDown;
    else if (paramName == "stepsizeSpeedUp")
        in >> stepsizeSpeedUp;
    else if (paramName == "stepsizeSpeedDown")
        in >> stepsizeSpeedDown;
    else if (paramName == "timedRunControlUpDist1")
        in >> timedRunControlUpDist1;
    else if (paramName == "timedRunControlUpDist2")
        in >> timedRunControlUpDist2;
    else if (paramName == "timedRunControlUpDist3")
        in >> timedRunControlUpDist3;
    else if (paramName == "timedRunNMax")
        in >> timedRunNMax;
    else if (paramName == "swipeSensitivity")
        in >> swipeSensitivity;
    else if (paramName == "swipeInverted")
        in >> swipeInverted;
    else
    {
        std::cout << "WARNING: UNKNOWN PARAMETER... " << paramName << " IGNORED" << std::endl;
        setMessage("WARNING: Unknown config parameter", MESSAGE_NOTIFY);
    }
}

bool Util::ConfigGlobal::loadConfig(int sid)
{
    std::string check, paramName, colon;
    char nextVal;
    
    std::ifstream in (configPath.c_str());
    if (!in.good())
    {
        in.open(configBackup.c_str());
        std::cout << "Loading config: " << configBackup << std::endl;
    }
    else
        std::cout << "Loading config: " << configPath << std::endl;
    if (!in.good()) return false;
    
    do {
        in >> check;
        if (check != "{") {
            std::cout << "ERROR: Config file missing \'{\' in "
            << "at least one Stage configuration" << std::endl;
            return false;
        }
        
        in >> paramName;
        while (paramName != "}" && !in.eof()) {
            in >> colon;
            nextVal = in.peek();
            setConfigValue(in, paramName);
            in >> paramName;
            
            if (colon == "{" || nextVal == '{' || paramName == "{" || in.eof()) {
                std::cout << "ERROR: Config file missing \'}\' in "
                << "at least one Stage configuration." << std::endl;
                in.close();
                return false;
            }
        }
        
    // *************** Would this mean that the parameters will not be read for the
    // current stage object since stageID is usually the first element? C.P.
    } while (stageID != sid && !in.eof());
    
    in.close();
    
    if (stageID == sid) {
        std::cout << "Loaded stageID " << stageID << std::endl;
        return true;
    } else {
        std::cout << "Failed to load stageID " << stageID << std::endl;
        return false;
    }
    
    return false;
}

bool Util::ConfigGlobal::loadSaveFile(std::string savePath)
{
    std::ifstream saveFile (savePath.c_str());
    bool ret = false;
    
    std::cout << "Loading player save: " << savePath << std::endl;
    
    if (saveFile.good()) {
        saveFile >> currStageID;
        std::cout << "Starting from last session StageID " << currStageID << std::endl;
        setMessage("Loaded Save " + playerName + "\nSwipe to Continue", MESSAGE_NORMAL);
        ret = true;
    } else {
        currStageID = 1;
        std::cout << "Starting from StageID " << currStageID << std::endl;
        setMessage("New Save " + playerName + "\nSwipe to Continue", MESSAGE_NORMAL);
        ret = false;
    }
    
    saveFile.close();
    return ret;
}

void Util::ConfigGlobal::setMessage(std::string msg, MessageType type)
{
    if (type > messageType)
    {
        message = msg;
        messageType = type;
    }
}

void Util::ConfigGlobal::clearMessage()
{
    message = "";
    messageType = MESSAGE_NONE;
}

bool Util::ConfigGlobal::setName(const char* name)
{
    std::string test = "subject000";
    playerName = name;
    if (playerName.length() != test.length())
        return false;
    
    if (playerName.substr(0, 7) != "subject")
        return false;
    
    int id = atoi(playerName.substr(7, 3).c_str());
    if (!((id >= 100 && id <= 200) || (id >= 900 && id <= 999)))
        return false;
    return true;
}

std::string Util::ConfigGlobal::buildLogPath(std::string playerName)
{
    //Get Date
    time_t raw = time(0);
    struct tm * timeinfo = localtime( &raw );
    char buffer [80];
    strftime(buffer, 80, "%F", timeinfo);
    
#if defined(OGRE_IS_IOS)
    std::string logPath = Util::getIOSDir() + "/" + playerName + "/"
    + playerName + "-" + std::string(buffer);
#else
    std::string logPath = Util::getOSXDir() + "/" + playerName + "/"
    + playerName + "-" + std::string(buffer);
#endif
    
    int i = 1;
    std::ifstream testExist (std::string(logPath + ".log").c_str());
    
    while (testExist) {
        testExist.close();
        logPath = logPath + "_" + Util::toStringInt(i);
        ++i;
        testExist.open(std::string(logPath + ".log").c_str());
    }
    
    logPath = logPath + ".log";
    
    return logPath;
}

float Util::clamp(float val, float min, float max)
{
    if (val < min)
        val = min;
    if (val > max)
        val = max;
    return val;
}

// Returns the degrees from 0-359 for a direction where SOUTH is 0
int Util::getDegrees(Direction dir)
{
	switch (dir)
	{
        case NORTHWEST:
            return 225;
        case NORTH:
            return 180;
        case NORTHEAST:
            return 135;
        case EAST:
            return 90;
        case SOUTHEAST:
            return 45;
        case SOUTH:
            return 0;
        case SOUTHWEST:
            return 270;
        case WEST:
            return 315;
        default:
            return 0;
	}
}

Direction Util::leftOf(Direction dir)
{
	switch (dir)
	{
        case NORTHWEST:
            return WEST;
        case NORTH:
            return NORTHWEST;
        case NORTHEAST:
            return NORTH;
        case EAST:
            return NORTHEAST;
        case SOUTHEAST:
            return EAST;
        case SOUTH:
            return SOUTHEAST;
        case SOUTHWEST:
            return SOUTH;
        case WEST:
            return SOUTHWEST;
        default:
            return NO_DIRECTION;
	}
}

Direction Util::rightOf(Direction dir)
{
	switch (dir)
	{
        case NORTHWEST:
            return NORTH;
        case NORTH:
            return NORTHEAST;
        case NORTHEAST:
            return EAST;
        case EAST:
            return SOUTHEAST;
        case SOUTHEAST:
            return SOUTH;
        case SOUTH:
            return SOUTHWEST;
        case SOUTHWEST:
            return WEST;
        case WEST:
            return NORTHWEST;
        default:
            return NO_DIRECTION;
	}
}

Direction Util::oppositeOf(Direction dir)
{
	switch (dir)
	{
        case NORTHWEST:
            return SOUTHEAST;
        case NORTH:
            return SOUTH;
        case NORTHEAST:
            return SOUTHWEST;
        case EAST:
            return WEST;
        case SOUTHEAST:
            return NORTHWEST;
        case SOUTH:
            return NORTH;
        case SOUTHWEST:
            return NORTHEAST;
        case WEST:
            return EAST;
        default:
            return NO_DIRECTION;
	}
}

void Util::setSides(bool sides[NUM_DIRECTIONS], int level, Direction dir)
{
    for (int i = 0; i < NUM_DIRECTIONS; ++i)
        sides[i] = false;
    switch (level)
    {
        case 1:
            sides[leftOf(dir)] = true;
            sides[dir] = true;
            sides[rightOf(dir)] = true;
            break;
        case 2:
            sides[leftOf(leftOf(dir))] = true;
            sides[leftOf(dir)] = true;
            sides[dir] = true;
            sides[rightOf(dir)] = true;
            sides[rightOf(rightOf(dir))] = true;
            break;
        case 3:
            sides[leftOf(leftOf(leftOf(dir)))] = true;
            sides[leftOf(leftOf(dir))] = true;
            sides[leftOf(dir)] = true;
            sides[dir] = true;
            sides[rightOf(dir)] = true;
            sides[rightOf(rightOf(dir))] = true;
            sides[rightOf(rightOf(rightOf(dir)))] = true;
            break;
        default:
            sides[NORTHWEST] = true;
            sides[WEST] = true;
            sides[SOUTHWEST] = true;
            sides[SOUTH] = true;
            sides[SOUTHEAST] = true;
            sides[EAST] = true;
            sides[NORTHEAST] = true;
            sides[NORTH] = true;
            break;
    }
    
}

Direction Util::randDirection()
{
    return (Direction)(rand() % NUM_DIRECTIONS);
}

Direction Util::randDirection(const bool sides[NUM_DIRECTIONS])
{
    std::vector<Direction> dirs;
    if (sides[NORTHWEST])
        dirs.push_back(NORTHWEST);
    if (sides[NORTH])
        dirs.push_back(NORTH);
    if (sides[NORTHEAST])
        dirs.push_back(NORTHEAST);
    if (sides[EAST])
        dirs.push_back(EAST);
    if (sides[SOUTHEAST])
        dirs.push_back(SOUTHEAST);
    if (sides[SOUTH])
        dirs.push_back(SOUTH);
    if (sides[SOUTHWEST])
        dirs.push_back(SOUTHWEST);
    if (sides[WEST])
        dirs.push_back(WEST);
    
    int randDirIndex = rand() % dirs.size();
    
    return dirs[randDirIndex];
}

Vector3 Util::randVector3()
{
    Vector3 temp(0, 1, 0);
    return temp.randomDeviant(Degree(randRangeFloat(0.0, 180.0)));
}


int Util::randRangeInt(int min, int max)
{
    return min + rand () % (max - min + 1);
}

float Util::randRangeFloat(float min, float max)
{
    return min + static_cast<float>(rand()) / RAND_MAX * (max - min);
}

std::string Util::toStringInt(int value)
{
    std::stringstream ss;
	ss << value;
	return ss.str();
}

std::string Util::toStringFloat(float value)
{
    std::stringstream ss;
    ss << std::setprecision(3) << std::fixed;
	ss << value;
	return ss.str();
}

std::string Util::getOSXDir()
{
    char * dir = getenv("HOME");
    std::string result = "";
    if (dir)
        result = std::string(dir) + "/braingame/Documents";
    else
        return "";
    
    mkdir(result.c_str(), 0777);
    return result;
}

std::string Util::getIOSDir()
{
    const char* dir = OgreFramework::getSingletonPtr()->getMacBundlePath().c_str();
    std::string result = "";
    if (dir)
        result = std::string(dir) + "/../Documents";
    else
        return "";
    
    mkdir(result.c_str(), 0777);
    return result;
}

void Util::drawRect(ManualObject* obj, float x, float y, float width, float height, const ColourValue & col, bool filled)
{
    float left = x;
    float right = x + width;
    float top = -y;
    float bottom = -(y + height);
    
    obj->clear();
    // Range is from x [-1, 1], y [-1, 1]
    obj->setUseIdentityProjection(true);
    obj->setUseIdentityView(true);
    obj->setQueryFlags(0);
    if (filled)
    {
        obj->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_TRIANGLE_LIST);
        obj->position(left, top, -1);
        obj->colour(col);
        obj->position(right, top, -1);
        obj->colour(col);
        obj->position(right, bottom, -1);
        obj->colour(col);
        obj->position(left, bottom, -1);
        obj->colour(col);
        obj->quad(3, 2, 1, 0);
        obj->end();
    }
    else
    {
        obj->begin("BaseWhiteNoLighting", Ogre::RenderOperation::OT_LINE_STRIP);
        obj->position(left, top, -1);
        obj->colour(col);
        obj->position(right, top, -1);
        obj->colour(col);
        obj->position(right, bottom, -1);
        obj->colour(col);
        obj->position(left, bottom, -1);
        obj->colour(col);
        obj->position(left, top, -1);
        obj->colour(col);
        obj->end();
    }
    obj->setBoundingBox(Ogre::AxisAlignedBox::BOX_INFINITE);
}

// http://www.ogre3d.org/tikiwiki/tiki-index.php?page=manualspheremeshes
void Util::createSphere(Ogre::SceneManager* sceneMgr, const std::string& strName, float r, int nRings, int nSegments)
{
    ManualObject * manual = sceneMgr->createManualObject(strName);
    manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);
    
    float fDeltaRingAngle = (Math::PI / nRings);
    float fDeltaSegAngle = (2 * Math::PI / nSegments);
    unsigned short wVerticeIndex = 0 ;
    
    // Generate the group of rings for the sphere
    for( int ring = 0; ring <= nRings; ring++ ) {
        float r0 = r * sinf (ring * fDeltaRingAngle);
        float y0 = r * cosf (ring * fDeltaRingAngle);
        
        // Generate the group of segments for the current ring
        for(int seg = 0; seg <= nSegments; seg++) {
            float x0 = r0 * sinf(seg * fDeltaSegAngle);
            float z0 = r0 * cosf(seg * fDeltaSegAngle);
            
            // Add one vertex to the strip which makes up the sphere
            manual->position( x0, y0, z0);
            
            manual->normal(Vector3(x0, y0, z0).normalisedCopy());
            manual->textureCoord((float) seg / (float) nSegments, (float) ring / (float) nRings);
            
            if (ring != nRings) {
                // each vertex (except the last) has six indicies pointing to it
                manual->index(wVerticeIndex + nSegments + 1);
                manual->index(wVerticeIndex);
                manual->index(wVerticeIndex + nSegments);
                manual->index(wVerticeIndex + nSegments + 1);
                manual->index(wVerticeIndex + 1);
                manual->index(wVerticeIndex);
                wVerticeIndex ++;
            }
        }; // end for seg
    } // end for ring
    manual->end();
    MeshPtr mesh = manual->convertToMesh(strName);
    mesh->_setBounds( AxisAlignedBox( Vector3(-r, -r, -r), Vector3(r, r, r) ), false );
    
    mesh->_setBoundingSphereRadius(r);
    unsigned short src, dest;
    if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
    {
        mesh->buildTangentVectors(VES_TANGENT, src, dest);
    }
    
    sceneMgr->destroyManualObject(manual);
}

void Util::createCylinder(Ogre::SceneManager* sceneMgr, const std::string& strName, float r, float h, int nSegments)
{
    ManualObject * manual = sceneMgr->createManualObject(strName);
    manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);
    
    float fDeltaSegAngle = (2 * Math::PI / nSegments);
    
    float x0 = 0;
    float y0 = -h / 2;
    float y1 = h / 2;
    float z0 = 0;
    
    manual->position(x0, y0, z0);
    manual->normal(Vector3(x0, y0, z0).normalisedCopy());
    manual->textureCoord(0.0, 0.0);
    manual->position(x0, y1, z0);
    manual->normal(Vector3(x0, y1, z0).normalisedCopy());
    manual->textureCoord(0.0, 1.0);
    
    unsigned short botVerticeIndex = 0;
    unsigned short topVerticeIndex = 1;
    unsigned short iVerticeIndex = 2;
    unsigned short wVerticeIndex = iVerticeIndex;
    
    for (int seg = 0; seg <= nSegments; ++seg)
    {
        x0 = r * sinf(seg * fDeltaSegAngle);
        z0 = r * cosf(seg * fDeltaSegAngle);
        
        manual->position(x0, y0, z0);
        manual->normal(Vector3(x0, 0, z0).normalisedCopy());
        manual->textureCoord((float) seg / (float) nSegments, 0.5);
        manual->position(x0, y1, z0);
        manual->normal(Vector3(x0, 0, z0).normalisedCopy());
        manual->textureCoord((float) seg / (float) nSegments, 0.5);
        
        if (seg > 1)
        {
            manual->triangle(botVerticeIndex, wVerticeIndex + 2, wVerticeIndex);
            manual->triangle(topVerticeIndex, wVerticeIndex + 1, wVerticeIndex + 3);
            manual->triangle(wVerticeIndex, wVerticeIndex + 2, wVerticeIndex + 1);
            manual->triangle(wVerticeIndex + 2, wVerticeIndex + 3, wVerticeIndex + 1);
            
            wVerticeIndex += 2;
        }
    }
    manual->triangle(botVerticeIndex, iVerticeIndex, wVerticeIndex); // last triangles
    manual->triangle(topVerticeIndex, wVerticeIndex + 1, iVerticeIndex + 1);
    manual->triangle(wVerticeIndex, iVerticeIndex, wVerticeIndex + 1);
    manual->triangle(iVerticeIndex, iVerticeIndex + 1, wVerticeIndex + 1);
    manual->end();
    
    MeshPtr mesh = manual->convertToMesh(strName);
    Vector3 bl = Vector3(-r, -h / 2, -r);
    Vector3 tr = Vector3(r, h / 2, r);
    mesh->_setBounds( AxisAlignedBox( bl, tr ), false );
    
    mesh->_setBoundingSphereRadius((tr - bl).length() / 2);
    unsigned short src, dest;
    if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
    {
        mesh->buildTangentVectors(VES_TANGENT, src, dest);
    }
    
    sceneMgr->destroyManualObject(manual);
}

void Util::createDiamond(Ogre::SceneManager* sceneMgr, const std::string& strName, float w, float h)
{
    ManualObject * manual = sceneMgr->createManualObject(strName);
    manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);
    
    manual->position(0, h, 0);
    manual->normal(0, 1, 0);
    manual->textureCoord(0.5, 1.0);
    manual->position(-w, 0, -w);
    manual->normal(-sqrt(2), 0, -sqrt(2));
    manual->textureCoord(0.0, 0.0);
    manual->position(w, 0, -w);
    manual->normal(sqrt(2), 0, -sqrt(2));
    manual->textureCoord(1.0, 0.0);
    manual->position(w, 0, w);
    manual->normal(sqrt(2), 0, sqrt(2));
    manual->textureCoord(1.0, 1.0);
    manual->position(-w, 0, w);
    manual->normal(-sqrt(2), 0, sqrt(2));
    manual->textureCoord(1.0, 0.0);
    manual->position(0, -h, 0);
    manual->normal(0, -1, 0);
    manual->textureCoord(0.5, 0.0);
    
    manual->triangle(4, 3, 0);
    manual->triangle(3, 2, 0);
    manual->triangle(2, 1, 0);
    manual->triangle(1, 4, 0);
    manual->triangle(1, 2, 5);
    manual->triangle(2, 3, 5);
    manual->triangle(3, 4, 5);
    manual->triangle(4, 1, 5);
    manual->end();
    
    MeshPtr mesh = manual->convertToMesh(strName);
    Vector3 bl = Vector3(-w, -h, -w);
    Vector3 tr = Vector3(w, h, w);
    mesh->_setBounds( AxisAlignedBox( bl, tr ), false );
    
    mesh->_setBoundingSphereRadius((tr - bl).length() / 2);
    unsigned short src, dest;
    if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
    {
        mesh->buildTangentVectors(VES_TANGENT, src, dest);
    }
    
    sceneMgr->destroyManualObject(manual);
}

void Util::createBox(Ogre::SceneManager* sceneMgr, const std::string& strName, float l, float w, float h)
{
    ManualObject * manual = sceneMgr->createManualObject(strName);
    manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);
    
    float mag = sqrt(l * l + w * w + h * h);
    
    manual->position(-l, -w, -h);
    manual->normal(-sqrt(mag), -sqrt(mag), -sqrt(mag));
    manual->textureCoord(0.0, 0.0);
    manual->position(l, -w, -h);
    manual->normal(sqrt(mag), -sqrt(mag), -sqrt(mag));
    manual->textureCoord(0.5, 0.0);
    manual->position(l, w, -h);
    manual->normal(sqrt(mag), sqrt(mag), -sqrt(mag));
    manual->textureCoord(0.5, 0.5);
    manual->position(-l, w, -h);
    manual->normal(-sqrt(mag), sqrt(mag), -sqrt(mag));
    manual->textureCoord(0.0, 0.5);
    manual->position(-l, -w, h);
    manual->normal(-sqrt(mag), -sqrt(mag), sqrt(mag));
    manual->textureCoord(0.5, 0.5);
    manual->position(l, -w, h);
    manual->normal(sqrt(mag), -sqrt(mag), sqrt(mag));
    manual->textureCoord(1.0, 0.5);
    manual->position(l, w, h);
    manual->normal(sqrt(mag), sqrt(mag), sqrt(mag));
    manual->textureCoord(1.0, 1.0);
    manual->position(-l, w, h);
    manual->normal(-sqrt(mag), sqrt(mag), sqrt(mag));
    manual->textureCoord(0.5, 1.0);
    manual->quad(3, 2, 1, 0);
    manual->quad(7, 6, 2, 3);
    manual->quad(4, 5, 6, 7);
    manual->quad(0, 1, 5, 4);
    manual->quad(1, 2, 6, 5);
    manual->quad(3, 0, 4, 7);
    
    manual->end();
    
    MeshPtr mesh = manual->convertToMesh(strName);
    Vector3 bl = Vector3(-l, -w, -h);
    Vector3 tr = Vector3(l, w, h);
    mesh->_setBounds( AxisAlignedBox( bl, tr ), false );
    
    mesh->_setBoundingSphereRadius((tr - bl).length() / 2);
    unsigned short src, dest;
    if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
    {
        mesh->buildTangentVectors(VES_TANGENT, src, dest);
    }
    
    sceneMgr->destroyManualObject(manual);
}

void Util::createPlane(Ogre::SceneManager* sceneMgr, const std::string& strName, float length, float depth)
{
    ManualObject * manual = sceneMgr->createManualObject(strName);
    manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);
    
    length += EPSILON;
    depth += EPSILON;
    
    manual->position(-length / 2, 0, -depth / 2);
    manual->normal(0, 1, 0);
    manual->textureCoord(0, 0);
    manual->position(length / 2, 0, -depth / 2);
    manual->normal(0, 1, 0);
    manual->textureCoord(1, 0);
    manual->position(length / 2, 0, depth / 2);
    manual->normal(0, 1, 0);
    manual->textureCoord(1, 1);
    manual->position(-length / 2, 0, depth / 2);
    manual->normal(0, 1, 0);
    manual->textureCoord(0, 1);
    manual->quad(3, 2, 1, 0);
    manual->end();
    
    MeshPtr mesh = manual->convertToMesh(strName);
    float len = length / 2;
    float dep = depth / 2;
    float diag1 = (Vector3(length, 0, depth) - Vector3(-length, 0, -depth)).length() / 2;
    float diag2 = (Vector3(length, 0, -depth) - Vector3(-length, 0, depth)).length() / 2;
    Vector3 bl = Vector3(-len, 0, -dep);
    Vector3 tr = Vector3(len, 0, dep);
    mesh->_setBounds( AxisAlignedBox( bl, tr ), true );
    
    mesh->_setBoundingSphereRadius(diag1 > diag2 ? diag1 : diag2);
    unsigned short src, dest;
    if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
    {
        mesh->buildTangentVectors(VES_TANGENT, src, dest);
    }
    
    sceneMgr->destroyManualObject(manual);
}

void Util::createSubPlane(Ogre::SceneManager* sceneMgr, ManualObject* manual, float length, float depth, Vector3 loc, Quaternion rot, Vector3 & bl, Vector3 & tr)
{
    manual->begin("BaseWhiteNoLighting", RenderOperation::OT_TRIANGLE_LIST);
    
    length += EPSILON;
    depth += EPSILON;
    
    Vector3 p1 = Vector3(-length / 2, 0, -depth / 2);
    Vector3 p2 = Vector3(length / 2, 0, -depth / 2);
    Vector3 p3 = Vector3(length / 2, 0, depth / 2);
    Vector3 p4 = Vector3(-length / 2, 0, depth / 2);
    Vector3 normal = Vector3(0, 1, 0);
    
    p1 = loc + rot * p1;
    p2 = loc + rot * p2;
    p3 = loc + rot * p3;
    p4 = loc + rot * p4;
    normal = rot * normal;
    
    manual->position(p1.x, p1.y, p1.z);
    manual->normal(normal.x, normal.y, normal.z);
    manual->textureCoord(0, 0);
    manual->position(p2.x, p2.y, p2.z);
    manual->normal(normal.x, normal.y, normal.z);
    manual->textureCoord(1, 0);
    manual->position(p3.x, p3.y, p3.z);
    manual->normal(normal.x, normal.y, normal.z);
    manual->textureCoord(1, 1);
    manual->position(p4.x, p4.y, p4.z);
    manual->normal(normal.x, normal.y, normal.z);
    manual->textureCoord(0, 1);
    manual->quad(3, 2, 1, 0);
    manual->end();
    
    bl = Vector3(fmin(bl.x, p1.x), fmin(bl.y, p2.y), fmin(bl.z, p1.z));
    bl = Vector3(fmin(bl.x, p2.x), fmin(bl.y, p2.y), fmin(bl.z, p2.z));
    bl = Vector3(fmin(bl.x, p3.x), fmin(bl.y, p3.y), fmin(bl.z, p3.z));
    bl = Vector3(fmin(bl.x, p4.x), fmin(bl.y, p4.y), fmin(bl.z, p4.z));
    tr = Vector3(fmax(tr.x, p1.x), fmax(tr.y, p2.y), fmax(tr.z, p1.z));
    tr = Vector3(fmax(tr.x, p2.x), fmax(tr.y, p2.y), fmax(tr.z, p2.z));
    tr = Vector3(fmax(tr.x, p3.x), fmax(tr.y, p3.y), fmax(tr.z, p3.z));
    tr = Vector3(fmax(tr.x, p4.x), fmax(tr.y, p4.y), fmax(tr.z, p4.z));
}

void Util::createSegment(Ogre::SceneManager* sceneMgr, const std::string& strName, float length, float depth, const bool sides[NUM_DIRECTIONS])
{
    ManualObject * manual = sceneMgr->createManualObject(strName);
    
	float wallLength = length / (2 * Math::Cos(Ogre::Radian(Math::PI) / 4) + 1);
    
    Vector3 bl = Vector3(Ogre::Math::POS_INFINITY, Ogre::Math::POS_INFINITY, Ogre::Math::POS_INFINITY);
    Vector3 tr = Vector3(Ogre::Math::NEG_INFINITY, Ogre::Math::NEG_INFINITY, Ogre::Math::NEG_INFINITY);
    
    Vector3 move;
    Quaternion rot;
    
    if (sides[NORTHWEST])
    {
        move = Vector3(-(length + wallLength) / 4, (length + wallLength) / 4, 0);
        rot.FromAngleAxis(Degree(225), Vector3(0, 0, 1));
        createSubPlane(sceneMgr, manual, wallLength, depth, move, rot, bl, tr);
    }
    
    if (sides[NORTH])
    {
        move = Vector3(0, length / 2, 0);
        rot.FromAngleAxis(Degree(180), Vector3(0, 0, 1));
        createSubPlane(sceneMgr, manual, wallLength, depth, move, rot, bl, tr);
    }
    
    if (sides[NORTHEAST])
    {
        move = Vector3((length + wallLength) / 4, (length + wallLength) / 4, 0);
        rot.FromAngleAxis(Degree(135), Vector3(0, 0, 1));
        createSubPlane(sceneMgr, manual, wallLength, depth, move, rot, bl, tr);
    }
    
    if (sides[EAST])
    {
        move = Vector3(length / 2, 0, 0);
        rot.FromAngleAxis(Degree(90), Vector3(0, 0, 1));
        createSubPlane(sceneMgr, manual, wallLength, depth, move, rot, bl, tr);
    }
    
    if (sides[SOUTHEAST])
    {
        move = Vector3((length + wallLength) / 4, -(length + wallLength) / 4, 0);
        rot.FromAngleAxis(Degree(45), Vector3(0, 0, 1));
        createSubPlane(sceneMgr, manual, wallLength, depth, move, rot, bl, tr);
    }
    
    if (sides[SOUTH])
    {
        move = Vector3(0, -length / 2, 0);
        rot.FromAngleAxis(Degree(0), Vector3(0, 0, 1));
        createSubPlane(sceneMgr, manual, wallLength, depth, move, rot, bl, tr);
    }
    
    if (sides[SOUTHWEST])
    {
        move = Vector3(-(length + wallLength) / 4, -(length + wallLength) / 4, 0);
        rot.FromAngleAxis(Degree(315), Vector3(0, 0, 1));
        createSubPlane(sceneMgr, manual, wallLength, depth, move, rot, bl, tr);
    }
    
    if (sides[WEST])
    {
        move = Vector3(-length / 2, 0, 0);
        rot.FromAngleAxis(Degree(270), Vector3(0, 0, 1));
        createSubPlane(sceneMgr, manual, wallLength, depth, move, rot, bl, tr);
    }
    
    MeshPtr mesh = manual->convertToMesh(strName);
    mesh->_setBounds( AxisAlignedBox( bl, tr ), true );
    
    float l = (tr - bl).length() / 2;
    mesh->_setBoundingSphereRadius(l);
    unsigned short src, dest;
    if (!mesh->suggestTangentVectorBuildParams(VES_TANGENT, src, dest))
    {
        mesh->buildTangentVectors(VES_TANGENT, src, dest);
    }

    sceneMgr->destroyManualObject(manual);
}

void Util::createDefaultSegments(Ogre::SceneManager* sceneMgr)
{
    bool sides[NUM_DIRECTIONS];
    for (int i = 0; i < NUM_DIRECTIONS; ++i)
        sides[i] = false;
    
    sides[SOUTHEAST] = true;
    sides[SOUTH] = true;
    sides[SOUTHWEST] = true;
    Util::createSegment(sceneMgr, "segmentMesh3", 1.0, 1.0, sides);
    
    sides[WEST] = true;
    sides[EAST] = true;
    Util::createSegment(sceneMgr, "segmentMesh5", 1.0, 1.0, sides);
    
    sides[NORTHWEST] = true;
    sides[NORTHEAST] = true;
    Util::createSegment(sceneMgr, "segmentMesh7", 1.0, 1.0, sides);
    
    sides[NORTH] = true;
    Util::createSegment(sceneMgr, "segmentMesh8", 1.0, 1.0, sides);
}

void Util::generateMaterials()
{
    /*
     MaterialPtr mat0 =
     MaterialManager::getSingleton().create("PodUnknownMaterial", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, true);
     mat0->setLightingEnabled(true);
     mat0->setAmbient(0.3, 0.3, 0.3);
     mat0->setDiffuse(0.3, 0.3, 0.3, 1.0);
     mat0->load();
     
     MaterialPtr mat1 =
     MaterialManager::getSingleton().create("PodRedMaterial", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, true);
     mat1->setLightingEnabled(true);
     mat1->setAmbient(0.5, 0.0, 0.0);
     mat1->setDiffuse(0.5, 0.0, 0.0, 1.0);
     mat1->load();
     
     MaterialPtr mat2 =
     MaterialManager::getSingleton().create("PodGreenMaterial", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, true);
     mat2->setLightingEnabled(true);
     mat2->setAmbient(0.0, 0.5, 0.0);
     mat2->setDiffuse(0.0, 0.5, 0.0, 1.0);
     mat2->load();
     
     MaterialPtr mat3 =
     MaterialManager::getSingleton().create("PodBlueMaterial", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, true);
     mat3->setAmbient(0.0, 0.0, 0.5);
     mat3->setDiffuse(0.0, 0.0, 0.5, 1.0);
     mat3->load();
     
     MaterialPtr mat4 =
     MaterialManager::getSingleton().create("PodYellowMaterial", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, true);
     mat4->setLightingEnabled(true);
     mat4->setAmbient(0.5, 0.5, 0.0);
     mat4->setDiffuse(0.5, 0.5, 0.0, 1.0);
     mat4->load();
     
     MaterialPtr mat5 =
     MaterialManager::getSingleton().create("StemMaterial", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, true);
     mat5->setLightingEnabled(true);
     mat5->setAmbient(0.25, 0.5, 0.25);
     mat5->setDiffuse(0.25, 0.5, 0.25, 1.0);
     mat5->load();
     
     MaterialPtr mat6 =
     MaterialManager::getSingleton().create("PodShellMaterial", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, true);
     mat6->setLightingEnabled(true);
     mat6->setAmbient(0.5, 0.0, 0.0);
     mat6->setDiffuse(0.5, 0.0, 0.0, 0.1);
     mat6->load();
     */
    
    /*
     Technique *technique = m->createTechnique();
     Pass *pass = technique->createPass();
     pass->setIlluminationStage(Ogre::IS_PER_LIGHT);
     pass->setVertexColourTracking(Ogre::TVC_DIFFUSE);
     pass->setAmbient(1.0, 0.0, 0.0);
     pass->setLightingEnabled(true);
     */
    
}