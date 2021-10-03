import random
import os
import game_config as gc

from pygame import image, transform
'''
image_count = dict((a, 0) for a in gc.ASSET_FILES)

def available_animals():
    return [animal for animal, count in image_count.items() if count < 2]
'''
def image_name(val):
    return str(val) + '.png'

class Image: #Animal
    def __init__(self, r,c, val):
        self.name = image_name(val)
        self.image_path = os.path.join(gc.ASSET_DIR, self.name)
        self.row = r 
        self.col = c 
        self.image = image.load(self.image_path)
        self.image = transform.scale(self.image, (gc.IMAGE_SIZE - 2 * gc.MARGIN, gc.IMAGE_SIZE - 2 * gc.MARGIN))
        self.box = self.image.copy()
        self.box.fill((200, 200, 200))

        #image_count[self.name] += 1

        #animals_count

if __name__ == '__main__':
    for i in range(len(gc.ASSET_FILES)):
        temp = Image(1,8,i)
        print(temp.name,temp.image_path,temp.box,temp)
