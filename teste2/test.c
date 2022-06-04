 #define BIT(n) 1<<n
 
uint8_t * video_mem;
uint16_t xres;
uint16_t yres;
uint8_t bytes_per_pixel;
uint16_t rpos;
uint16_t gpos;

int draw_pixel(uint16_t x, uint16_t y, uint16_t len, uint32_t color){
    uint8_t *ptr = (uint8_t *)video_mem + x*bytes_per_pixel + y * x_res*bytes_per_pixel;

    uint8_t r=(color>>16) & (BIT((1<<rsize))-1);
    uint8_t g=(color>>8) & (BIT()-1);
    uint8_t b=(color) & (BIT()-1);
    color= r<<rpos | g<<gpos | b<<bpos;
    memcpy(ptr, &color, bytes_per_pixel);
}

int pp_test_line(uint8_t mode, enum lpv_dir_t dir, uint16_t x, uint16_t y, uint16_t len, uint32_t color, uint32_t delay){
    lpv_get_mode_info(mode, &lmi_p);

    uint32_t ph_addr=lmi_p.phys_addr;
    xres=lmi_p.x_res;
    yres=lmi_p.y_res;
    bytes_per_pixel =(lmi_p.bbp+7)/8;
    size_t len = bytes_per_pixel*yres*xres; 
    rpos = lmi_p.r_pos;

    video_mem =video_map_phys(ph_addr, len);
    lpv_set_mode(uint16_t mode);

    switch (dir)
    {
    case lpv_hor:
        for (unsigned int i = 0; i < len; i++)
        {
            draw_pixel(x+i,y,color);
        }         
        break;
    
    case lpv_vert:
        for (unsigned int i = 0; i < len; i++)
        {
            draw_pixel(x,y+i,color);
        }
        
        break;
    }
    sleep(delay);
    
}