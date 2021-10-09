import os

IMAGE_SIZE = 32
SCREEN_SIZE = 321
NUM_TILES_SIDE = 10
NUM_TILES_TOTAL = 100
MINES = 10
MARGIN = 2

ASSET_DIR = 'assets'
ASSET_FILES = [x for x in os.listdir(ASSET_DIR) if x[-3:].lower() == 'png']
#assert len(ASSET_FILES) == 13